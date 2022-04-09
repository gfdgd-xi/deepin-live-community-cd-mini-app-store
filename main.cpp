/*
 ********************************************************************************
 * 作者：gfdgd xi                                                               *
 * 版本：1.0.0                                                                  *
 * 更新时间：2022年04月09日                                                     *
 * 需要依赖：toilet                                                             *
 * 理论支持系统：Windows、Linux                                                 *
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
using namespace std;
const int listNumber = 20;
const int projectUrlNumber = 2;
const string updateTime = "2022年04年09日";
const string projectUrl[projectUrlNumber] = {"https://gitee.com/gfdgd-xi/deepin-live-community-cd-mini-app-store", "https://github.com/gfdgd-xi/deepin-live-community-cd-mini-app-store"};
const string version = "1.0.0";
const int contTipsWidth = 30;
const int programListNumber = 3;
const string checkOption[2] = {"", "-y"};
string list1[listNumber] = {"deepin 应用商店", "deepin 启动盘制作工具", "deepin 计算器", "deepin 相机", "deepin 邮件", "deepin 帮助", "deepin 视频", "deepin 音乐", "deepin 文档查看器", "deepin 备份还原工具", "deepin 磁盘管理", "deepin 字体管理器", "deepin 终端", "deepin 看图", "deepin 安装器", "deepin 日志收集工具", "deepin 语言记事本", "deepin-wine6", "deepin-wine5"};
string list2[listNumber] = {"CPU-Z", "FurMark", "Keyboard_Test_Utility"};
string list3[listNumber] = {"deepin 应用商店", "星火应用商店"};
string list1PackageName[listNumber] = {"deepin-app-store", "deepin-boot-maker", "deepin-calculator", "deepin-camera", "deepin-mail", "deepin-manual", "deepin-movie", "deepin-music", "deepin-reader", "deepin-clone", "deepin-diskmanager", "deepin-font-manager", "deepin-terminal", "deepin-image-viewer", "deepin-installer", "deepin-log-viewer", "deepin-voice-note", "deepin-wine6-stable", "deepin-wine5-stable"};
string list2PackageName[listNumber] = {"https://download.fastgit.org/gfdgd-xi/program-internet-library/releases/download/CPU-Z/CPUZ.zip", "https://download.fastgit.org/gfdgd-xi/program-internet-library/releases/download/FurMark/FurMark.zip", "https://download.fastgit.org/gfdgd-xi/program-internet-library/releases/download/Keyboard-Test-Utility/Keyboard.Test.Utility.zip"};
string list3PackageName[listNumber] = {"deepin-app-store", "spark-store"};
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
		system(("sudo apt install deepin-wine6-stable -y" + checkOption[o.notCheck]).c_str());
		system("deepin-wine6-stable exit");
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
		ofstream files;
		files.open("/tmp/test.txt");
		files << "请选择您要安装的应用（可以使用方向键操作指针），然后输入 :q 退出再输入要安装应用前面对应的编号：" << endl;
		for(int i=0;i<listNumber;i++){
			files << i + 1 << ". " << list[i] << endl;
		}
		files.close();
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
				cout << "程序作者：gfdgd xi" << endl;
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
				cout << setw(4) << "-y        安装无需用户确认（即输入Y）" << endl;
				return 1; // 停止参数的判断
			}

		}
		return 0;
	}
	/*void InstallChoose(string tipsInformation, char command[50]){
		string input;
		cout << tipsInformation << "[Y/N]";
		getline(cin, input);
		if(input == "Y" || input == "y"){
			system(command);
		}

	}
	void ShowSharp(){
		for(int i=0;i<contTipsWidth;i++){
			cout << "#";
		}
		cout << endl;
	}*/
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
		cout << "在查看应用列表时，退出查看时，需要输入 :q 进行退出" << endl;
		cout << "如果您想更好的使用，可以学习 vim 的操作！" << endl;
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
		string command_str = ("sudo apt update && sudo apt install " + checkOption[o.notCheck] + " ").c_str();
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
		//char command[500] = "deepin-wine6-stable ";
		//char ExePath[100];
		//strcpy(ExePath, ExePath_str.c_str());
		//strcat(command, "");


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
		//desktopFile << "Name[zh]=社区论坛" << endl;
		desktopFile << "Type=Application" << endl;
		desktopFile << "X-Deepin-Vendor=deepin" << endl;
		desktopFile.close();
		string temp;
		cout << "按回车后继续……";
		getline(cin, temp);
	}
}

int main(int argc, char** argv) {
	// 进行赋值
	o.argc = argc;
	o.argv = argv;
	// 判断是否有获取参数
	if(::GetHelp()){return 0;} // 判断是否有帮助参数，有的话显示帮助内容后关闭程序
	//cin>>a;
	//GetInput(&a);
	//A::InstallChoose("是否安装星火应用商店？", "spark-store");
	//cout << a;
	ShowReady();
	ClearConsole();
	ShowTips();
	ClearConsole();
	ShowWelcome();
	bool firstRun = true;
	while(1){
		if(!firstRun){
			ShowChoose();
		}
		cout << "选择要安装的应用分类：" << endl;
		cout << "1. deepin 全家桶" << endl;
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
		system("vim /tmp/test.txt");
		cout << "请输入要选择安装的应用所对的编号：" << endl;
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
