#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void) {
    FILE *fp = fopen("vv.md", "r");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    // 统计行数
    int line_count = 0;
    {
        char temp[1024];
        while (fgets(temp, sizeof(temp), fp) != NULL) {
            line_count++;
        }
    }

    if (line_count == 0) {
        fprintf(stderr, "文件没有内容或无法读取有效行数！\n");
        fclose(fp);
        return 1;
    }

    // 分配存储 token 的指针数组
    char **tokens = (char **)malloc(line_count * sizeof(char *));
    if (!tokens) {
        fprintf(stderr, "内存分配失败！\n");
        fclose(fp);
        return 1;
    }

    // 重置文件指针到开头重新读取行内容
    fseek(fp, 0, SEEK_SET);

    // 读取每一行放入 tokens 数组中
    int i = 0;
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp) != NULL && i < line_count) {
        // 移除换行符
        buffer[strcspn(buffer, "\r\n")] = '\0';

        // 动态分配一块内存保存该行
        tokens[i] = (char *)malloc(strlen(buffer) + 1);
        if (!tokens[i]) {
            fprintf(stderr, "内存分配失败！\n");
            // 出错时释放已分配内存
            for (int j = 0; j < i; j++) {
                free(tokens[j]);
            }
            free(tokens);
            fclose(fp);
            return 1;
        }
        strcpy(tokens[i], buffer);
        i++;
    }

    fclose(fp);

    // 使用 time(NULL) 初始化随机数种子
    srand((unsigned int)time(NULL));

    // 随机选择一个 token 的索引
    int random_index = rand() % line_count;

    // 构建完整的 URL
    const char *base_url = "https://chatgpt.aicnm.cc/?token=";
    char url[2048];
    snprintf(url, sizeof(url), "%s%s", base_url, tokens[random_index]);

    printf("即将打开的URL：%s\n", url);

    // Windows 下使用 start 命令打开浏览器
    char command[2100];
    snprintf(command, sizeof(command), "start \"\" \"%s\"", url);
    system(command);

    // 释放内存
    for (int k = 0; k < line_count; k++) {
        free(tokens[k]);
    }
    free(tokens);

    return 0;
}
