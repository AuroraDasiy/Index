你好！很高兴你对这个 `tg-signer` 项目感兴趣。作为一个刚学习 Python 的大一学生，我会尽量以简单易懂的方式指导你如何安装和使用这个项目。以下是详细步骤：

### 1. 准备工作

在开始之前，请确保你已经安装了以下软件：

- **Python**：建议使用 Python 3.7 及以上版本。你可以从[官网下载](https://www.python.org/downloads/)并安装。
- **pip**：Python 的包管理工具，通常会随 Python 一起安装。
- **Git**（可选）：用于克隆项目代码。如果你打算直接使用源码，可以安装 Git 从[这里](https://git-scm.com/)下载。

### 2. 安装 `tg-signer`

你可以通过 `pip` 来安装 `tg-signer`。打开命令行（Windows 下是 CMD 或 PowerShell，macOS/Linux 下是终端），然后输入以下命令：

```sh
pip install -U tg-signer
```

如果你希望提升程序的运行速度，可以使用带有 `speedup` 选项的安装命令：

```sh
pip install "tg-signer[speedup]"
```

### 3. 登录 Telegram 账号

在使用 `tg-signer` 之前，你需要先登录你的 Telegram 账号以获取会话信息。

运行以下命令：

```sh
tg-signer login
```

根据提示输入你的手机号码和收到的验证码。登录成功后，程序会获取你最近的聊天列表，确保你要签到的聊天在列表中。

### 4. 配置代理（如果需要）

如果你在访问 Telegram 时需要代理，可以通过设置环境变量 `TG_PROXY` 或者在命令中使用 `--proxy` 参数来配置代理。例如：

设置环境变量（适用于当前终端会话）：

```sh
export TG_PROXY=socks5://127.0.0.1:7890
```

或者在命令中直接指定代理：

```sh
tg-signer run --proxy socks5://127.0.0.1:7890
```

### 5. 运行签到任务

`tg-signer` 可以帮助你自动进行每日签到。运行以下命令来开始配置和执行签到任务：

```sh
tg-signer run
```

系统会提示你进行相关配置，例如：

```
开始配置任务<linuxdo>
第1个签到
1. Chat ID（登录时最近对话输出中的ID）: 10086
2. 签到文本（如 /sign）: /check_in
3. 等待N秒后删除签到消息（发送消息后等待进行删除, '0'表示立即删除, 不需要删除直接回车）, N: 5
继续配置签到？(y/N)：n
4. 每日签到时间（如 06:00:00）: 08:10:00
5. 签到时间误差随机秒数（默认为0）: 10
```

根据提示输入相应的信息即可完成配置。

**注意**：
- **Chat ID**：这是你要签到的聊天的唯一标识符。你可以通过运行 `tg-signer list` 来查看你的聊天列表及其对应的 ID。
- **签到文本**：通常是一个命令，如 `/sign` 或 `/check_in`，具体取决于你要签到的群组或频道的要求。
- **签到时间**：设定每天自动签到的时间，格式为 `HH:MM:SS`。

### 6. 发送一次消息

你也可以使用 `tg-signer` 发送消息到特定的聊天。比如，向 `chat_id` 为 `8671234001` 的聊天发送 "hello"：

```sh
tg-signer send-text 8671234001 hello
```

如果 `chat_id` 是负数（通常用于群组或频道），需要在命令中使用 `--` 来区分参数，例如：

```sh
tg-signer send-text -- -10006758812 浇水
```

你还可以设置消息在发送后自动删除，例如在 1 秒后删除：

```sh
tg-signer send-text --delete-after 1 8671234001 /test
```

### 7. 配置与运行监控

`tg-signer` 还支持监控特定聊天中的消息，并根据规则自动回复。配置和运行监控任务的步骤如下：

```sh
tg-signer monitor run my_monitor
```

根据提示进行配置。例如：

```
开始配置任务<my_monitor>
聊天chat id和用户user id均同时支持整数id和字符串username, username必须以@开头，如@neo

配置第1个监控项
1. Chat ID（登录时最近对话输出中的ID）: -4573702599
2. 匹配规则('exact', 'contains', 'regex'): contains
3. 规则值（不可为空）: kfc
4. 只匹配来自特定用户ID的消息（多个用逗号隔开, 匹配所有用户直接回车）: @neo
5. 默认发送文本: V Me 50
6. 从消息中提取发送文本的正则表达式:
7. 等待N秒后删除签到消息（发送消息后等待进行删除, '0'表示立即删除, 不需要删除直接回车）, N:
继续配置？(y/N)：y

配置第2个监控项
...
```

**配置解释**：
1. **Chat ID 和 User ID**：可以是整数 ID 或者以 `@` 开头的用户名。
2. **匹配规则**：
   - `exact`：精确匹配，消息必须完全等于规则值。
   - `contains`：包含匹配，消息中包含规则值即可。
   - `regex`：正则表达式匹配，支持复杂的模式匹配。
3. **默认发送文本**：当匹配到规则时自动发送的回复内容。
4. **提取发送文本的正则表达式**：如果需要从消息中提取特定内容作为回复，可以使用正则表达式。

### 8. 查看和管理配置

- **列出已有配置**：

  ```sh
  tg-signer list
  ```

- **查看群组或频道的成员**（需要管理员权限）：

  ```sh
  tg-signer list-members --chat_id <CHAT_ID> --admin
  ```

- **重新配置任务**：

  ```sh
  tg-signer reconfig <任务名>
  ```

- **登出账号**：

  ```sh
  tg-signer logout
  ```

### 9. 数据与配置存储

所有的数据和配置默认保存在 `.signer` 目录中。你可以通过以下命令查看目录结构：

```sh
tree .signer
```

输出示例：

```
.signer
├── latest_chats.json  # 获取的最近对话
├── me.json  # 个人信息
├── monitors  # 监控
│   ├── my_monitor  # 监控任务名
│       └── config.json  # 监控配置
└── signs  # 签到任务
    └── linuxdo  # 签到任务名
        ├── config.json  # 签到配置
        └── sign_record.json  # 签到记录
```

### 10. 使用 Docker（可选）

如果你熟悉 Docker，可以选择使用 Docker 来运行 `tg-signer`。不过，对于初学者，建议先通过 `pip` 方式安装和使用。

### 11. 其他命令

- **运行一次签到任务**（即使当天已执行过）：

  ```sh
  tg-signer run-once <任务名>
  ```

- **查看版本**：

  ```sh
  tg-signer version
  ```

### 12. 获取帮助

你可以随时通过以下命令获取更多帮助和命令说明：

```sh
tg-signer --help
```

或查看特定子命令的帮助，例如：

```sh
tg-signer send-text --help
```

### 总结

以上就是使用 `tg-signer` 项目的基本步骤。作为一个仅学习过 Python 的大一学生，这些命令行操作应该是可行的。建议你逐步尝试每一步，确保每个环节都能顺利完成。如果在使用过程中遇到问题，可以参考项目的 [README](#) 文件，或者在项目的 GitHub 仓库中提交 issue 寻求帮助。

祝你使用愉快！