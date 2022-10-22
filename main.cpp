/*
 ********************************************************************************
 * 作者：gfdgd xi、为什么您不喜欢熊出没和阿布呢                                 *
 * 版本：1.1.0                                                                  *
 * 更新时间：2022年07月22日                                                     *
 * 需要依赖：toilet、nano                                                       *
 * 理论支持系统：Linux                                                          *
 * 推荐运行系统：Deepin Live Commununity CD                                     *
 * 项目地址：https://gitee.com/gfdgd-xi/deepin-live-community-cd-mini-app-store *
 * https://github.com/gfdgd-xi/deepin-live-community-cd-mini-app-store          *
 ********************************************************************************
 */
#include <iostream>
#include <istream>
#include <sstream>
#include <unistd.h>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <jsoncpp/json/json.h>
using namespace std;
const int listNumber = 30;
const int projectUrlNumber = 2;
const string updateTime = "2022年07月22日";
const string projectUrl[projectUrlNumber] = {"https://gitee.com/gfdgd-xi/deepin-live-community-cd-mini-app-store", "https://github.com/gfdgd-xi/deepin-live-community-cd-mini-app-store"};
const string version = "1.1.0";
const int contTipsWidth = 30;
const int programListNumber = 3;
const string checkOption[2] = {"", "-y"};
string list1[listNumber] = {"deepin 应用商店", "deepin 启动盘制作工具", "deepin 计算器", "deepin 相机", "deepin 邮件", "deepin 帮助", "deepin 视频", "deepin 音乐", "deepin 文档查看器", "deepin 备份还原工具", "deepin 磁盘管理", "deepin 字体管理器", "deepin 终端", "deepin 看图", "deepin 安装器", "deepin 日志收集工具", "deepin 语言记事本", "deepin-wine6", "deepin-wine5", "安卓模拟器（UEngine）", "apt fast", "QQ（原生版）", "Firefox ESR", "网易云音乐", "fsearch", "简易倒计时工具", "Virtualbox", "qemu", "Wine 运行器"};
string list2[listNumber] = {"CPU-Z", "FurMark", "Keyboard_Test_Utility", "DisplayX", "NTPWEdit"};
string list3[listNumber] = {"deepin 应用商店", "星火应用商店", "星火应用商店终端版"};
string list1PackageName[listNumber] = {"deepin-app-store", "deepin-boot-maker", "deepin-calculator", "deepin-camera", "deepin-mail", "deepin-manual", "deepin-movie", "deepin-music", "deepin-reader", "deepin-clone", "deepin-diskmanager", "deepin-font-manager", "deepin-terminal", "deepin-image-viewer", "deepin-installer", "deepin-log-viewer", "deepin-voice-note", "deepin-wine6-stable spark-deepin-wine-runner", "deepin-wine5-stable spark-deepin-wine-runner", "com.gitee.uengine.runner.spark", "apt-fast", "linuxqq", "firefox-esr", "netease-cloud-music", "fsearch-trunk", "spark.gitee.timer", "virtualbox-6.1", "qemu", "spark-deepin-wine-runner"};
string list2PackageName[listNumber] = {"https://download.fastgit.org/gfdgd-xi/program-internet-library/releases/download/CPU-Z/CPUZ.zip", "https://download.fastgit.org/gfdgd-xi/program-internet-library/releases/download/FurMark/FurMark.zip", "https://download.fastgit.org/gfdgd-xi/program-internet-library/releases/download/Keyboard-Test-Utility/Keyboard.Test.Utility.zip", "https://download.fastgit.org/gfdgd-xi/program-internet-library/releases/download/DisplayX/DisplayX.zip", "https://download.fastgit.org/gfdgd-xi/program-internet-library/releases/download/NTPWEdit/NTPWEdit.zip"};
string list3PackageName[listNumber] = {"deepin-app-store", "spark-store", "spark-store-console"};
string *programList[programListNumber] = {list1, list2, list3};
string *programListPackageName[programListNumber] = {list1PackageName, list2PackageName, list3PackageName};
struct Opt{
	int argc;
	char** argv;
	bool notCheck;
};
Opt o;
namespace {
	void ShowInstall(){
		system("toilet Install!");
	}
	bool Is_DeepinWine6Install(){
		ifstream file;
		file.open("/usr/bin/deepin-wine6-stable");
		bool state = file.is_open();
		file.close();
		return state;
	}
	void DownloadFile(string url_str, string file_str){
		char url[1000];
		char file[1000];
		char command[5000] = "sudo wget -P ";
		strcpy(url, url_str.c_str());
		strcpy(file, file_str.c_str());
		strcat(command, file);
		strcat(command, " ");
		strcat(command, url);
		system(command);
	}
	void InstallDeepinWine6(){
		system("sudo apt update");
		system(("sudo apt install spark-deepin-wine-runner deepin-wine6-stable -y" + checkOption[o.notCheck]).c_str());
		system("deepin-wine6-stable exit");
		cout << "安装常见字体" << endl;
		DownloadFile("https://download.fastgit.org/gfdgd-xi/program-internet-library/releases/download/Simsun/simsun.ttc", "~/.wine/drive_c/windows/Fonts");
		DownloadFile("https://download.fastgit.org/gfdgd-xi/program-internet-library/releases/download/Simsun/simsunb.ttf", "~/.wine/drive_c/windows/Fonts");
		system("sudo chmod 777 ~/.wine/drive_c/windows/Fonts/*");

	}
	void Unzip(string file_str, string unzipPath_str){
		char file[50];
		char unzipPath[50];
		char command[100] = "sudo unzip ";
		strcpy(file, file_str.c_str());
		strcpy(unzipPath, unzipPath_str.c_str());
		strcat(command, file);
		strcat(command, " -d ");
		strcat(command, unzipPath);
		system(command);
	}
	void WriteProgramList(int id){
		string *list = programList[id - 1];
		//ofstream files;
		//files.open("/tmp/test.txt");
		cout << "请选择您要安装的应用，输入要安装应用前面对应的编号：" << endl;
		for(int i=0;i<listNumber;i++){
			cout << i + 1 << ". " << list[i] << endl;
		}
		//files.close();
	}
	int GetHelp(){
		for(int i=1;i<o.argc;i++){
			if(strcmp(o.argv[i], "-y") == 0){
				o.notCheck = true;
			}
			else if(strcmp(o.argv[i], "--version") == 0){
				cout << "软件版本：" << version << endl;
				return 1; // 停止参数的判断
			}
			else if(strcmp(o.argv[i], "--about") == 0){
				cout << "程序版本：" << version << endl;
				cout << "程序作者：gfdgd xi、为什么您不喜欢熊出没和阿布呢" << endl;
				cout << "更新时间：" << updateTime << endl;
				cout << "项目链接：" << endl;
				for(int i=0;i<projectUrlNumber;i++){
					cout << setw(4) << projectUrl[i] << endl;
				}
				return 1;
			}
			else if(strcmp(o.argv[i], "--help") == 0 || strcmp(o.argv[i], "/?") == 0){ // 判断参数有没有“--help”或“/?”
				// 这种比较方式比较慢如果参数比较长
				cout << "帮助：" << endl;
				cout << setw(4) << "--help    显示帮助" << endl;
				cout << setw(4) << "--version 显示版本" << endl;
				cout << setw(4) << "--about   关于这个软件" << endl;
				cout << setw(4) << "-y        安装无需用户确认（即输入Y）（已废弃）" << endl;
				return 1; // 停止参数的判断
			}

		}
		return 0;
	}
	void ShowReady(){
		system("toilet Ready!");
	}
	void ShowWelcome(){
		system("toilet Welcome!");
	}
	void ShowChoose(){
		system("toilet Choose!");
	}
	void ShowTips(){
		system("toilet Tips!");
		cout << "在查看应用列表时，退出查看时，需要按下 Ctrl+X 进行退出" << endl;
		cout << "如果您想更好的使用，可以学习 nano 的操作！" << endl;
		cout << "以及安装其它应用需要连接互联网" << endl;
		cout << "按下回车键继续运行" << endl;
		string temp;
		getline(cin, temp);
	}
	void ClearConsole(){
		// Unix
		system("clear");
		// Windows
		//system("cls");
	}
	bool CheckNumber(string str){
		try{
			atoi(str.c_str());
			return true;
		}
		catch(...){
			return false;
		}
	}
	void InstallProgram(int id, int listID){
		ClearConsole();
		string *list = programListPackageName[id - 1];
		string *name = programList[id - 1];
		string command_str = ("sudo apt update && sudo apt install " + checkOption[o.notCheck] + " -y").c_str();
		char command[1000];
		strcpy(command, command_str.c_str());
		char package[50];
		strcpy(package, list[listID - 1].c_str());
		strcat(command, package);
		ShowInstall();
		cout << "正在安装应用“" << name[listID - 1] << "”" << endl;
		system(command);
		string temp;
		cout << "按回车后继续……";
		getline(cin, temp);
	}
	void InstallWineApp(int id){
		ClearConsole();
		ShowInstall();
		// 检测 depein-wine6-stable 是否安装
		if(!Is_DeepinWine6Install()){
			cout << "您没有安装 Deepin-Wine6-Stable，是否安装？[Y/N]";
			string choose;
			getline(cin, choose);
			if(choose == "Y" || choose == "y"){
				InstallDeepinWine6();
			}
			else{
				return;
			}
		}
		cout << "正在安装：" << list2[id - 1] << endl;
		system(("sudo touch /usr/share/applications/" + list2[id - 1] + ".desktop").c_str());
		system(("sudo chmod 777 /usr/share/applications/" + list2[id - 1] + ".desktop").c_str());
		system("sudo mkdir /opt/apps/wine-app > /dev/null");
		system("sudo rm -rfv /tmp/download-wine-app/");
		system(("sudo rm -rfv /opt/apps/wine-app/" + list2[id - 1]).c_str());
		system("sudo mkdir /tmp/download-wine-app");
		DownloadFile(list2PackageName[id - 1], "/tmp/download-wine-app");
		Unzip("/tmp/download-wine-app/*", "/opt/apps/wine-app/" + list2[id - 1]);
		ofstream desktopFile;
		desktopFile.open("/usr/share/applications/" + list2[id - 1] + ".desktop");
		desktopFile << "[Desktop Entry]" << endl;
		desktopFile << "Conmment=" << list2[id - 1] << endl;
		desktopFile << "Exec=deepin-wine6-stable /opt/apps/wine-app/" << list2[id - 1] << "/main.exe" << endl;
		desktopFile << "Icon=deepin-clone" << endl;
		desktopFile << "Name=" << list2[id - 1] << endl;
		desktopFile << "Type=Application" << endl;
		desktopFile << "X-Deepin-Vendor=deepin" << endl;
		desktopFile.close();
		string temp;
		cout << "按回车后继续……";
		getline(cin, temp);
	}
	string GetAPI(){
		string url = "http://120.25.153.144/deepin-live-community-cd-mini-app-store/AppList.json";
		string command = "curl ";
		string returnCommand = "";
		command += url + " > /tmp/return.txt";
		// 执行命令
		system(command.c_str());
		ifstream file;
		file.open("/tmp/return.txt");
		char part[200] = "";
		while(!file.eof()){
			string read;
			file >> read;
			returnCommand += read;
		}
		file.close();
		return returnCommand;
	}
	struct Internet{
		Json::Value internetList;
	};
	Internet internet;
	void WriteProgramListInternet(int id){
		int list = internet.internetList[id - 1].size();
		//ofstream files;
		//files.open("/tmp/test.txt");
		cout << "请选择您要安装的应用，输入要安装应用前面对应的编号：" << endl;
		for(int i=0;i<list;i++){
			cout << i + 1 << ". " << internet.internetList[id - 1][i].asString() << endl;
		}
		//files.close();
		
		//cout << GetAPI();
		//sleep(50000);
	}
	void InstallProgramInternet(int id, int listID){
		ClearConsole();
		ShowInstall();
		string name = internet.internetList[id - 1 + 3][listID - 1].asString();
		string command_str = ("sudo apt update && sudo apt install " + name).c_str();
		cout << "正在安装应用“" << internet.internetList[id - 1][listID - 1] << "”" << endl;
		system(command_str.c_str());
		string temp;
		cout << "按回车后继续……";
		getline(cin, temp);
	}
	void InstallWineAppInternet(int id){
		ClearConsole();
		ShowInstall();
		// 检测 depein-wine6-stable 是否安装
		if(!Is_DeepinWine6Install()){
			cout << "您没有安装 Deepin-Wine6-Stable，是否安装？[Y/N]";
			string choose;
			getline(cin, choose);
			if(choose == "Y" || choose == "y"){
				InstallDeepinWine6();
			}
			else{
				return;
			}
		}
		string name = internet.internetList[1][id - 1].asString();
		string url = internet.internetList[4][id - 1].asString();
		cout << "正在安装：" << name << endl;
		system(("sudo touch /usr/share/applications/" + name + ".desktop").c_str());
		system(("sudo chmod 777 /usr/share/applications/" + name + ".desktop").c_str());
		system("sudo mkdir /opt/apps/wine-app > /dev/null");
		system("sudo rm -rfv /tmp/download-wine-app/");
		system(("sudo rm -rfv /opt/apps/wine-app/" + name).c_str());
		system("sudo mkdir /tmp/download-wine-app");
		DownloadFile(url, "/tmp/download-wine-app");
		Unzip("/tmp/download-wine-app/*", "/opt/apps/wine-app/" + name);
		ofstream desktopFile;
		desktopFile.open("/usr/share/applications/" + name + ".desktop");
		desktopFile << "[Desktop Entry]" << endl;
		desktopFile << "Conmment=" << name << endl;
		desktopFile << "Exec=deepin-wine6-stable /opt/apps/wine-app/" << name << "/main.exe" << endl;
		desktopFile << "Icon=deepin-clone" << endl;
		desktopFile << "Name=" << name << endl;
		desktopFile << "Type=Application" << endl;
		desktopFile << "X-Deepin-Vendor=deepin" << endl;
		desktopFile.close();
		string temp;
		cout << "按回车后继续……";
		getline(cin, temp);
	}
	int GetInternetList(){
		Json::Reader reader;
		Json::Value value;
		if(!reader.parse(GetAPI(), value)){
			return 1;
		}		
		reader.parse(GetAPI(), internet.internetList);
		ClearConsole();
		ShowWelcome();
		bool firstRun = true;
		while(1){
			if(!firstRun){
				ShowChoose();
			}
			cout << "选择要安装的应用分类（在线列表）：" << endl;
			cout << "1. 常见应用" << endl;
			cout << "2. wine 应用" << endl;
			cout << "3. 应用商店" << endl;
			cout << "E. 退出程序" << endl;
			cout << "请输入要选择安装的应用分类（输入 E 或 e 取消）：" << endl;
			string choose;
			string chooseProgram;
			getline(cin, choose);
			if(choose == "e" || choose == "E"){
				break;
			}
			if(!CheckNumber(choose) || atoi(choose.c_str()) < 1 || atoi(choose.c_str()) > 3){
				cout << "输入的不是数字或范围内内容，无法继续！" << endl;
				cout << "按回车键继续……";
				string temp;
				getline(cin, temp);
				ClearConsole();
				firstRun = false;
				continue;
			}
			WriteProgramListInternet(atoi(choose.c_str()));
			cout << "请输入要选择安装的应用所对的编号（输入 E 或 e 取消）：" << endl;
			getline(cin, chooseProgram);
			if(chooseProgram == "E" || chooseProgram == "e"){
				ClearConsole();
				firstRun = false;
				continue;
			}
			if(atoi(choose.c_str()) == 2){
				InstallWineAppInternet(atoi(chooseProgram.c_str()));
				ClearConsole();
				firstRun = false;
				continue;
			}
			InstallProgramInternet(atoi(choose.c_str()), atoi(chooseProgram.c_str()));
			ClearConsole();
			firstRun = false;
		}
		return 0;
	}
}

int main(int argc, char** argv) {
	// 进行赋值
	o.argc = argc;
	o.argv = argv;
	// 判断是否有获取参数
	if(::GetHelp()){return 0;} // 判断是否有帮助参数，有的话显示帮助内容后关闭程序
	ShowReady();
	ClearConsole();
	ShowTips();
	if(!GetInternetList()){
		return 0;	
	}
	ClearConsole();
	ShowWelcome();
	bool firstRun = true;
	while(1){
		if(!firstRun){
			ShowChoose();
		}
		cout << "选择要安装的应用分类（离线列表）：" << endl;
		cout << "1. 常见应用" << endl;
		cout << "2. wine 应用" << endl;
		cout << "3. 应用商店" << endl;
		cout << "E. 退出程序" << endl;
		cout << "请输入要选择安装的应用分类：" << endl;
		string choose;
		string chooseProgram;
		getline(cin, choose);
		if(choose == "e" || choose == "E"){
			break;
		}
		if(!CheckNumber(choose) || atoi(choose.c_str()) < 1 || atoi(choose.c_str()) > 3){
			cout << "输入的不是数字或范围内内容，无法继续！" << endl;
			cout << "按回车键继续……";
			string temp;
			getline(cin, temp);
			ClearConsole();
			firstRun = false;
			continue;
		}
		WriteProgramList(atoi(choose.c_str()));
		//system("nano /tmp/test.txt");
		cout << "请输入要选择安装的应用所对的编号（输入 E 或 e 取消）：" << endl;
		getline(cin, chooseProgram);
		if(chooseProgram == "E" || chooseProgram == "e"){
			ClearConsole();
			firstRun = false;
			continue;
		}
		if(atoi(choose.c_str()) == 2){
			InstallWineApp(atoi(chooseProgram.c_str()));
			ClearConsole();
			firstRun = false;
			continue;
		}
		InstallProgram(atoi(choose.c_str()), atoi(chooseProgram.c_str()));
		ClearConsole();
		firstRun = false;
	}
	return 0;
}
