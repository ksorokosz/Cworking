#!/bin/bash
#
#Usage: 
# $ ./Cworking_Regression_Testing.sh [-r | --create-reference] testcase_file
#
#Description:
# Regression test framework. Script 
# - compares results of some program with reference files
# - generate reference files from results
# - allows to simply define testcases
#
#Arguments
# -r or --create-reference: create reference mode [optional]
# testcase_file: path to file with testcases
#
#Author: cworking.wordpress.com
#

# Get arguments
ARGUMENTS=`getopt -o "r" -l "create-reference" -n "$0"  -- "$@"`

# Unknown arguments
if [ $? != 0 ] ; then echo "Terminating..." >&2 ; exit 1 ; fi

# Evaluate ARGUMENTS
eval set -- "$ARGUMENTS"

# Initialize switches
create_reference_switch=0

# For each argument
while true ; do
    case "$1" in
        -r|--create-reference) create_reference_switch=1 ; shift ;;
        --)                                                shift ; break ;;
         *) echo "Internal error!" ; exit 1 ;;
    esac
done

# Check if test case file is defined
if [ -z $1 ]; then
	echo "Please provide test case file"
	exit 1;
fi

# Get path to testcases
testcases_path=$1

# Set path to reference files
reference_path=./References

# Get test cases
testcases=`sed -n "/BEG_TEST_CASE/,/END_TEST_CASE/p" $testcases_path`

# Get test cases names
testcases_names=`echo "$testcases" | sed -n "/BEG_TEST_CASE/p" | sed -e "s/BEG_TEST_CASE \(.*\)/\1/"`

# Create file
if [ $create_reference_switch -eq 0 ]; then
	echo "Start regression testing: $(date)" > ./status.log
	echo "Start regression testing: $(date)" > ./errors.log
fi

# For each test case
echo "$testcases_names" | while read LINE;
do
	# Get test case
	testcase_name=$LINE

	# Get current test case block
	testcase_body=`echo "$testcases" | 
                       sed -n "/^BEG_TEST_CASE $testcase_name$/,/^END_TEST_CASE $testcase_name$/p" |
                       sed -e "s/^BEG_TEST_CASE $testcase_name$//" -e "s/^END_TEST_CASE $testcase_name$//" |
                       tr  -d '\t'`

	# Get command (application name with arguments) 
	app_command=`echo "$testcase_body" | tr "\n" " "`

	# Run command in appropriate mode
	if [ $create_reference_switch -eq 1 ]; then

		# Generate reference file
		eval $app_command > $reference_path/$testcase_name.reference
	else
		# Run tests
		if [ ! -f $reference_path/$testcase_name.reference ]; then
			
			# Message 			
			echo "Reference doesn't exist"

			# Exit
			exit 1;
		fi

		# Run command
		differences=`diff $reference_path/$testcase_name.reference <(eval $app_command)`

		# Number of differences
		number_of_differences=`diff $reference_path/$testcase_name.reference <(eval $app_command) | wc -l`

		# Check number of differences	
		if [ $number_of_differences -gt 0 ]; then
			echo "$testcase_name FAILS" >> ./status.log
			echo -e "<<<<<< $testcase_name >>>>>>\n$differences\n"  >> ./errors.log
		else
			echo "$testcase_name SUCCESS" >> ./status.log				
		fi
			
	fi
	
done

if [ $create_reference_switch -eq 0 ]; then
	echo "Finish regression testing: $(date)" >> ./errors.log
	echo "Finish regression testing: $(date)" >> ./status.log
fi
