# 一、安装

## 1.1 安装步骤

1. 下载安装器，地址：https://visualstudio.microsoft.com/zh-hans/

2. 启动安装器，选择要使用的功能模块：C++桌面开发、Visual Stdio扩展
3. 更改安装路径、缓存路径以及共享组件、工具和SDK的位置。

## 1.2 可能存在的问题：

1. 共享组件、工具和SDK的位置不能更改：

   >产生原因：上次卸载后，注册表未清理。
   >
   >解决方法：删除注册表，步骤如下：
   >
   >1. WIN + R 输入 regedit 打开注册表
   >2. HKEY_LOCAL_MACHINE => SOFTWARE => Microsoft => VisualStudio => Setup 
   >3. 删除 **SharedInstallationPath** 

2. vs安装目录所在盘符的根目录下生成Windows Kits

   >- 该目录为Windows10 SDK开发环境。
   >
   >- 安装时由VS安装器更新注册表指定安装位置。
   >
   >- 微软官方提供的解决方法如下：
   >
   >```
   >Try the following technique:
   >
   >Close all programs, move the “Windows Kits” folder to another disk, for example to “D:\Windows Kits”; remove the original folder.
   >Start the “Command Prompt (Admin)”. It can be found in Start menu. If you find “PowerShell (Admin)”, then start it and execute “cmd”. Then run the command:
   >mklink /J "C:\Program Files (x86)\Windows Kits" "D:\Windows Kits"
   >
   >You should re-see “Windows Kits” at original location on disk C, but now it is a “junction” and does not take space. The programs do not need re-configuration.
   >```
   >

# 二、使用







