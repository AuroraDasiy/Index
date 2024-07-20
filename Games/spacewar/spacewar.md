要在VBScript中初始化SteamAPI并将游戏伪装成Spacewar，需要创建一个VBScript文件，并通过运行该脚本来设置所需的配置。这包括创建`steam_appid.txt`文件并启动你的游戏。

以下是一个示例VBScript代码，用于创建`steam_appid.txt`文件并启动你的游戏：

1. **创建`steam_appid.txt`文件**：
2. **启动游戏**：

```vbscript
' VBScript to create steam_appid.txt and run the game

Option Explicit

Dim fso, appIDFile, shell

' Create FileSystemObject
Set fso = CreateObject("Scripting.FileSystemObject")

' Create steam_appid.txt and write AppID 480
Set appIDFile = fso.CreateTextFile("steam_appid.txt", True)
appIDFile.WriteLine("480")
appIDFile.Close

' Create Shell object
Set shell = CreateObject("WScript.Shell")

' Run the game executable
' Replace "YourGameExecutable.exe" with the path to your game executable
shell.Run "YourGameExecutable.exe"

' Clean up
Set fso = Nothing
Set appIDFile = Nothing
Set shell = Nothing
```

### 使用说明：

1. **保存脚本**：
   - 将上面的代码复制并粘贴到一个文本编辑器中，保存文件为`RunGame.vbs`。

2. **修改游戏路径**：
   - 将脚本中的`YourGameExecutable.exe`替换为你实际的游戏可执行文件的路径。

3. **运行脚本**：
   - 双击`RunGame.vbs`文件运行脚本。脚本将创建`steam_appid.txt`文件，并启动你的游戏。

### 警告：

正如之前提到的，将游戏伪装成Spacewar可能违反Steam的使用条款，可能导致你的Steam账户被封禁。请谨慎操作，并了解相关风险。建议仅在开发和测试环境中使用这些方法，不要在正式发布的游戏中使用。如果被发现，你可能会面临严重的后果，包括账户封禁和潜在的法律问题。