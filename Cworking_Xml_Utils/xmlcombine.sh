#!/bin/bash -ue
#
# Script combines XML trees
#

xml_first=$1; shift
xml_second=$1; shift
node_name=$1; shift
node_level=$1; shift

start=0
while IFS= read -r LINE
do

	if [[ $LINE =~ \<$node_name\> ]]; then
		start=$(( $start + 1 ))
	fi

	if [[ $LINE =~ \</$node_name\> ]]; then
		if [ $start -eq $node_level ]; then
			perl -pe "s|(.*?)<(.*?)>(.*)</|\1<\2>\n\1\t\3\n\1</|" $xml_second 
		fi
		start=$(( $start - 1 ))
	fi
	echo -e "$LINE"

done < <(perl -pe "s|(.*?)<(.*?)>(.*)</|\1<\2>\n\1\t\3\n\1</|" $xml_first)
