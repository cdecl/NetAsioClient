
Dim o, sRecvMsg, nRecv
Dim sMessage

sMessage = "2000023302002000023310000201101040040090400030020000004000027855920000000BYS  38769078169705  인터파크INT         0408660000000052000김은정              0000000000000                             004          "

Set o = CreateObject("NetAsioCom.SocketClient")
nRecv = o.SendPacket("211.233.74.71", "22001", 10, sMessage, sRecvMsg)

MsgBox nRecv & " : " & sRecvMsg

