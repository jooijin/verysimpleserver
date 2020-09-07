#include <string>
#include <iostream>

#define USER_MAX 10000
#define ID_LEN_MAX 20
#define PW_LEN_MAX 20
#define CODE_MAX 20

/**

 * @mainpage	간단한 회원관리 서버 프로그램

 * @brief		서버 관리

 * @details		사용자와 관리자, 회원가입자를 관리할 수 있는 간단한 서버 프로그램이다.

*/


using namespace std;

int waitingNum = 0; /**< 가입 대기 회원수 */


/**

 * @brief		서버를 표현하기 위한 자료구조

*/
struct ServerInfo
{
	int Total = 100; /**< 전체용량 */
	int Using = 0; /**< 현재사용용량 */
	int addMemoryCount = 0; /**< 용량 추가 횟수 */
};


/**

 * @brief		사용자를 표현하기 위한 자료구조

*/
struct UserInfo
{
	char* ID; /**< 사용자의 ID를 저장 */
	char* Password; /**< 사용자의 비밀번호를 저장 */
	char* Autho; /**< 사용자의 권한레벨을 저장 */
	char* CitizenNum; /**< 가입회원의 주민번호를 저장 */
	int LogInCount = 0; /**< 사용자의 로그인 시도 횟수를 저장 */
	bool Sleep = false; /**< 휴면인지 아닌지 확인 */
};


/**

 * @brief		관리자를 표현하기 위한 자료구조

*/
struct AdminInfo
{
	char* Code; /**< 관리자의 코드를 저장 */ 
};


/**

 * @brief		서버를 관리하는 클래스

 * @details		가입한 유저와 대기중인 유저의 정보를 설정할 수 있고 서버의 용량을 관리할 수 있다.

 * @date		2020-09-04

 * @version		0.0.1

*/
class Server
{
public:
	/**

	* @brief		Server 클래스 생성자

	* @details		테스트를 위한 기본 유저 정보를 설정해준다.

	*/
	Server()
	{
		UI[0].ID = "testID";
		UI[0].Password = "testPW";
		UI[0].Autho = "RW";
		UI[0].LogInCount = 3;
		UI[0].CitizenNum = "1234567890123";
		UI[0].Sleep = false;
	}

	int getTotal() /**< 전체 용량을 반환 */
	{
		return SI.Total;
	}
	int getUsing() /**< 사용중인 용량을 반환 */
	{
		return SI.Using;
	}
	void addMemory() /**< 용량 추가 */
	{
		if (SI.addMemoryCount <= 3)
		{
			SI.Total = 2 * SI.Total;
			SI.addMemoryCount++;
		}
		else
			cout << "3회 이상 용량 추가는 불가능합니다" << endl;
	}
	char* getID(int i) /**< 사용자의 ID를 읽어옴 */
	{
		return UI[i].ID;
	}
	char* getPassword(int i) /**< 사용자의 비밀번호를 읽어옴 */
	{
		return UI[i].Password;
	}
	char* getAutho(int i) /**< 사용자의 권한레벨을 읽어옴 */
	{
		return UI[i].Autho;
	}
	bool getSleep(int i) /**< 사용자의 휴면 계정 여부를 읽어옴 */
	{
		return UI[i].Sleep;
	}
	int getLoginCount(int i) /**< 로그인 시도 횟수를 반환 */
	{
		return UI[i].LogInCount;
	}
	void addLoginCount(int i) /**< 로그인 시도 횟수를 +1 */
	{
		UI[i].LogInCount++;
	}
	void sleepAccount(int i) /**< 유저의 계정을 휴면 전환 */
	{
		UI[i].Sleep = true;
	}
	void saveTempID(int n, char* tempID) /**< 승인요청 아이디 */
	{
		n = waitingNum;
		waiting[n].ID = tempID;
	}
	void saveTempPass(int n, char* tempPass) /**< 승인요청 패스워드 */
	{
		n = waitingNum;
		waiting[n].Password = tempPass;
	}
	void saveTempCitizenNum(int n, char* tempCitizenNum) /**< 승인요청 주민번호 */
	{
		n = waitingNum;
		waiting[n].CitizenNum = tempCitizenNum;
	}
	void saveTempAutho(int n, char* tempAutho) /**< 승인요청 권한 */
	{
		n = waitingNum;
		waiting[n].Autho = tempAutho;
	}
	void showWaitList() /**< 대기중인 유저 정보 */
	{
		for (int i = 0; i < sizeof(waiting); i++)
		{
			cout << "<대기중인 유저>" << endl;
			cout << "아이디: " << waiting[i].ID << endl;
			cout << "패스워드: ****" << endl;
			cout << "주민번호: *************" << endl;
			cout << "신청권한: " << waiting[i].Autho << endl;
		}
	}
	void signedUser() /**< 가입한 유저 정보 */
	{
		for (int i = 0; i < sizeof(UI); i++)
		{
			cout << "<승인된 유저>" << endl;
			cout << "아이디: " << getID(i) << endl;
			cout << "비밀번호: ****" << endl;
			cout << "사용권한: " << getAutho(i) << endl;
			if (getSleep(i) == true)
				cout << "휴면계정" << endl;
		}
	}
	void uploadFile() /**< 파일 업로드 */
	{
		cout << "파일 업로드 완료" << endl;
	}
	void deleteFile() /**< 파일 삭제 */
	{
		cout << "파일 삭제 완료" << endl;
	}
	void downloadFile() /**< 파일 다운로드 */
	{
		cout << "파일 다운로드 완료" << endl;
	}
	/**

	* @brief		회원가입 화면을 출력하는 메서드

	* @details		회원 가입을 하려는 유저의 정보를 UserInfo 구조체 waiting에 저장한다. 유효하지 않은 비밀번호를 입력할 시 경고메시지를 출력한다.

	* @param		n 대기중인 회원 수
		
	*/
	void SignUp(int n)
	{
		char tempID[ID_LEN_MAX], tempPass[PW_LEN_MAX], tempCitizenNum[13], tempAutho[2];
		bool flagInvalid = false;
		while (1)
		{
			cin >> tempID >> tempPass >> tempCitizenNum >> tempAutho;

			if (strlen(tempPass) < 8 || strstr(tempPass, tempCitizenNum) != NULL)
			{
				cout << "유효하지 않은 패스워드" << endl;
				continue;
			}
			else
			{
				for (int i = 0; i < sizeof(tempPass); i++)
				{
					if (tempPass[i] < '0' || ('9' < tempPass[i] && tempPass[i] < 'A') || ('Z' < tempPass[i] && tempPass[i] < 'a') || 'z' < tempPass[i])
					{
						cout << "유효하지 않은 패스워드" << endl;
						flagInvalid = true;
					}
				}
				if (flagInvalid == true)
					continue;

				saveTempID(n, tempID);
				saveTempPass(n, tempPass);
				saveTempCitizenNum(n, tempCitizenNum);
				saveTempAutho(n, tempAutho);
				n++;
				break;
			}
		}
	}
private:
	struct UserInfo UI[USER_MAX];
	struct ServerInfo SI;
	struct UserInfo waiting[USER_MAX];
};


/**

 * @brief		유저 모드를 관리하는 클래스

 * @details		유저 모드로 들어갔을 시 나오는 화면을 출력하고, 유저가 사용하는 기능들을 조작한다.

 * @date		2020-09-04

 * @version		0.0.1

*/
class UserMode
{
public:
	/**

	* @brief		사용자 모드 로그인 화면을 출력하는 메서드

	* @details		사용자가 입력한 아이디와 패스워드와 일치하는 계정이 존재하는지 확인한다.
	
	*/
	void LoginPage()
	{
		char* inputID = new char[ID_LEN_MAX];
		char* inputPassword = new char[PW_LEN_MAX];

		while (true)
		{
			cout << "ID: ";
			cin >> inputID;
			cout << "password : ";
			cin >> inputPassword;
			for (int i = 0; i < USER_MAX; i++)
			{
				if (server.getLoginCount(i) >= 5)
				{
					server.sleepAccount(i);
					cout << "Your account is locked.";
					break;
				}

				if (strcmp(inputID, server.getID(i)) == 0 && strcmp(inputPassword, server.getPassword(i)) == 0)
				{
					LogInSuccess();
					break;
				}

				else if (strcmp(inputID, server.getID(i)) == 0 && strcmp(inputPassword, server.getPassword(i)) != 0)
				{
					server.addLoginCount(i);
					cout << "Wrong Password!";
					break;
				}
			}
			cout << "Wrong ID!";
		}
	}
	/**

	* @brief		로그인에 성공했을 시 화면을 출력하는 메서드

	* @details		사용자가 사용할 수 있는 기능들을 실행한다.

	*/
	void LogInSuccess()
	{
		int select;

		cout << "서버 전체용량: " << server.getTotal() << endl;
		cout << "현재 사용용량: " << server.getUsing() << endl;
		cout << "사용가능 용량" << server.getTotal() - server.getUsing() << endl<<endl;
		cout << "1. 파일 업로드" << endl;
		cout << "2. 파일 삭제" << endl;
		cout << "3. 파일 다운로드" << endl;

		cin >> select;

		switch (select)
		{
		case 1: 
			cout << "업로드할 파일을 선택하세요" << endl;
			server.uploadFile();
			break;
		case 2:
			cout << "삭제할 파일을 선택하세요" << endl;
			server.deleteFile();
			break;
		case 3:
			cout << "다운로드할 파일을 선택하세요" << endl;
			server.downloadFile();
			break;
		}
	}

private:
	Server server;
};


/**

 * @brief		관리자 모드를 관리하는 클래스

 * @details		관리자 모드로 들어갔을 시 나오는 화면을 출력하고, 관리자가 사용하는 기능들을 조작할 수 있다.

 * @date		2020-09-04

 * @version		0.0.1

*/
class AdminMode
{
public:
	/**

	* @brief		관리자 코드 입력 화면을 출력하는 메서드

	* @details		관리자가 올바른 코드를 입력하면 관리자 모드 화면으로 넘어간다.

	*/
	void AdminPage()
	{
		char* inputCode = new char[CODE_MAX];
		while (true)
		{
			cout << "Code: ";
			cin >> inputCode;
			if (strcmp(inputCode, getAdminCode()) == 0)
				CodeSuccess();
			else
				cout << "Wrong Code!";
		}
	}
	/**

	* @brief		관리자 코드 입력 성공시 나오는 화면을 출력하는 메서드

	* @details		관리자가 사용할 수 기능을 실행한다.

	*/
	void CodeSuccess()
	{
		int select;

		cout << "1. 관리자 코드 변경" << endl;
		cout << "2. 가입한 유저 정보" << endl;
		cout << "3. 하드용량 추가" << endl;
		cout << "4. 대기중인 유저 정보" << endl;
		cout << "5. 파일 업로드" << endl;
		cout << "6. 파일 삭제" << endl;
		cout << "7. 파일 다운로드" << endl;

		cin >> select;

		switch (select)
		{

		case 1:
			changeCode();
		case 2:
			server.signedUser();
		case 3:
			server.addMemory();
		case 4:
			server.showWaitList();
		case 5:
			server.uploadFile();
		case 6:
			server.deleteFile();
		case 7:
			server.downloadFile();
		}
	}
	char* getAdminCode() //관리자의 코드를 읽어옴
	{
		return AI.Code;
	}
	void changeCode() //관리자 코드 변경
	{
		char* temp = new char[CODE_MAX];
		cout << "변경할 코드: ";
		cin >> temp;
		AI.Code = temp;
	}

private:
	struct AdminInfo AI;
	Server server;
};

int main()
{
	int Select;
	UserMode UM;
	AdminMode AM;
	Server SV;

	cout << "1. 사용자 모드" <<endl<< "2. 관리자 모드" <<endl<< "3. 회원가입 요청"<<endl;
	cin >> Select;

	while (true)
	{
		if (Select != 1 || Select != 2 || Select != 3)
			cout << "Wrong Number!" << endl;

		if (Select == 1)
			UM.LoginPage(); //사용자 화면으로

		else if (Select == 2)
			AM.AdminPage(); //관리자 화면으로

			else if (Select == 3)
			SV.SignUp(waitingNum); //회원가입 화면으로
	}
	return 0;
}