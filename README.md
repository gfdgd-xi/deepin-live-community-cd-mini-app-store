# Introduce
It's a little app store on deepin community live cd, it can easyer to install some apps like some wine apps and some Linux apps than before.
# About The Deepin Community Live CD Introduce
It is made from Deepin 20.5 by gfdgd xi, it have some drivers to keep your computer run this deepin community live cd, The last version is 1.0.4.  
***Live CD defult password: 123456***  
![image.png](https://storage.deepin.org/thread/202204111533273090_image.png)  
![image.png](https://storage.deepin.org/thread/202204111534405194_image.png)  
## Some Include Tools
1. UOS Remote Desktop
2. TestDisk
3. Ukoapp
4. Deepin Repair Tools
5. CPU-G/CPU-X
6. GParted
7. Character Map
8. Timeshift
9. Lub
10. All Deepin Apps
11. Todesk
12. Live CD Tools By UOS(Will be not used)
13. Pardus Boot Repair
14. PowerISO
15. A small app store(this app)
16. Deepin Clone
17. ……

# How to Get Deepin Community Live CD
You can get on down link, also you can [press here](https://bbs.deepin.org/post/166409) to know how to build a Linux Live CD for yourself.    
## Deepin Forum
1.0.4：https://bbs.deepin.org/post/234831
1.0.3：https://bbs.deepin.org/post/234197  
1.0.2：https://bbs.deepin.org/post/233620  
1.0.1：https://bbs.deepin.org/post/233272  
## UOS Forum
1.0.4：https://bbs.chinauos.com/zh/post/11891
1.0.3：https://bbs.chinauos.com/zh/post/11793  
1.0.2：https://bbs.chinauos.com/zh/post/11708  
1.0.1：https://bbs.chinauos.com/zh/post/11618  
## UOS Club
1.0.4：https://club.uniontech.com/#/detail?id=b49daa4e781346618c6432228da09ea2
1.0.3：https://club.uniontech.com/#/detail?id=2fc8de40f1a044bd975f91a3afdd6f12  
1.0.2：https://club.uniontech.com/#/detail?id=897eb193fd834343a31c0838c89cce2c  
1.0.1：https://club.uniontech.com/#/detail?id=bc804ffe6dc14f13a4ddbc26447a5c62  
## Cloud Download Link
Baidu Cloud Disk：Link: [https://pan.baidu.com/s/1n5J8M8iqfI-kMbmHfR-x9w](https://pan.baidu.com/s/1n5J8M8iqfI-kMbmHfR-x9w) 提取码: ejr7  
![image.png](https://storage.deepin.org/thread/202203201435562540_image.png)

Aliyun Cloud Disk(Need to change file name)：[https://www.aliyundrive.com/s/bfzZhFWCEdi](https://www.aliyundrive.com/s/bfzZhFWCEdi)  
139 Cloud Disk：链接: [https://caiyun.139.com/m/i?0r5CLA9upgtMT](https://caiyun.139.com/m/i?0r5CLA9upgtMT) 提取码:nEy6  
![qrcode-分享.jpeg](https://storage.deepin.org/thread/202203201439423300_qrcode-%E5%88%86%E4%BA%AB.jpeg)

# How To Run This App
## Must Know: If you want to use this app well, you should add deepin and spark store apt sources in your Linux system.
If you are install and add in path environment, you can input it:  
```bash
deepin-live-community-cd-mini-app-store
```
You can press <kbd>Ctrl</kbd>+<kbd>Alt</kbd>+<kbd>T</kbd> to open console terminal, and you should input down code in your console terminal:  
```bash
sudo apt install git g++ toilet
git clone https://gitee.com/gfdgd-xi/deepin-live-community-cd-mini-app-store
# Or
# git clone https://github.com/gfdgd-xi/deepin-live-community-cd-mini-app-store
cd deepin-live-community-cd-mini-app-store
g++ main.cpp -o main
chmod 777 main
./main
# If you want to run like it:
# $>deepin-live-community-cd-mini-app-store
# Can run, you can do it:
sudo cp main deepin-live-community-cd-mini-app-store
```