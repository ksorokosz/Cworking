' This is a VBA library for mail processing with an example

Sub MailProcessing 

    Dim ns As NameSpace
    Dim Inbox As MAPIFolder
    Dim Item As Object
    Dim Atmt As Attachment
    Dim FileName As String
    Dim Output As String

    Output = "D:\Attachments"

    Set ns = GetNamespace("MAPI")
    Set Inbox = ns.GetDefaultFolder(olFolderInbox)

    ' No messages = finish
    If Inbox.Items.Count = 0 Then

       MsgBox "There are no messages in the Inbox.", vbInformation, _
              "Nothing Found"
       Exit Sub
    End If

    ' For each email in Inbox
    For Each Item In Inbox.Items

         If TypeOf Item Is Outlook.MailItem Then
            Dim oMail As Outlook.MailItem: Set oMail = Item

            If oMail.SenderEmailAddress = "author@gmail.com" Then ' Filter emails in terms on sender

                DownloadAttachments oMail, Output

                ' Here you could process an attachment or email

                MoveMail oMail, Inbox, "Data\Client"

            End If
        End If
    Next Item
End Sub


Function CreateFolder(InboxFolder As Outlook.Folder, OutputFolderPath As String) As Outlook.Folder

    Dim ArrayFolders() As String
    Dim CurrentFolder As Outlook.Folder
    ArrayFolders = Split(OutputFolderPath, "\")

    Set CurrentFolder = InboxFolder
    On Error Resume Next ' In VBA it means that we ignore error. Here error will occur in case no ChildFolder exist
    For Each ChildFolder In ArrayFolders

        Dim TargetFolder As Outlook.Folder
        Set TargetFolder = Nothing
        Set TargetFolder = CurrentFolder.Folders(ChildFolder) 'In case ChildFolder doesn't exist it will be created in the next command

        If TargetFolder Is Nothing Then
            Set CurrentFolder = CurrentFolder.Folders.Add(ChildFolder)
        Else
            Set CurrentFolder = TargetFolder
        End If

    Next ChildFolder
    Set CreateFolder = CurrentFolder

End Function

Sub MoveMail(oMail As Outlook.MailItem, InboxFolder As Outlook.Folder, OutputFolderPath As String)

    Dim TargetFolder As Object
    Set TargetFolder = CreateFolder(InboxFolder, OutputFolderPath)
    oMail.Move TargetFolder

End Sub

' For Debug purposes
Sub PrintMail(oMail As Outlook.MailItem)

    Debug.Print oMail.SenderEmailAddress, oMail.ReceivedTime

End Sub

Sub DownloadAttachments(oMail As Outlook.MailItem, Output As String)

    For Each Atmt In oMail.Attachments
        FileName = Output & Atmt.FileName
        Atmt.SaveAsFile FileName
    Next Atmt

End Sub

