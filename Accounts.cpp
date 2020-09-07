#include <string>
#include <iostream>

#define USER_MAX 10000
#define ID_LEN_MAX 20
#define PW_LEN_MAX 20
#define CODE_MAX 20

/**

 * @mainpage	������ ȸ������ ���� ���α׷�

 * @brief		���� ����

 * @details		����ڿ� ������, ȸ�������ڸ� ������ �� �ִ� ������ ���� ���α׷��̴�.

*/


using namespace std;

int waitingNum = 0; /**< ���� ��� ȸ���� */


/**

 * @brief		������ ǥ���ϱ� ���� �ڷᱸ��

*/
struct ServerInfo
{
	int Total = 100; /**< ��ü�뷮 */
	int Using = 0; /**< ������뷮 */
	int addMemoryCount = 0; /**< �뷮 �߰� Ƚ�� */
};


/**

 * @brief		����ڸ� ǥ���ϱ� ���� �ڷᱸ��

*/
struct UserInfo
{
	char* ID; /**< ������� ID�� ���� */
	char* Password; /**< ������� ��й�ȣ�� ���� */
	char* Autho; /**< ������� ���ѷ����� ���� */
	char* CitizenNum; /**< ����ȸ���� �ֹι�ȣ�� ���� */
	int LogInCount = 0; /**< ������� �α��� �õ� Ƚ���� ���� */
	bool Sleep = false; /**< �޸����� �ƴ��� Ȯ�� */
};


/**

 * @brief		�����ڸ� ǥ���ϱ� ���� �ڷᱸ��

*/
struct AdminInfo
{
	char* Code; /**< �������� �ڵ带 ���� */ 
};


/**

 * @brief		������ �����ϴ� Ŭ����

 * @details		������ ������ ������� ������ ������ ������ �� �ְ� ������ �뷮�� ������ �� �ִ�.

 * @date		2020-09-04

 * @version		0.0.1

*/
class Server
{
public:
	/**

	* @brief		Server Ŭ���� ������

	* @details		�׽�Ʈ�� ���� �⺻ ���� ������ �������ش�.

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

	int getTotal() /**< ��ü �뷮�� ��ȯ */
	{
		return SI.Total;
	}
	int getUsing() /**< ������� �뷮�� ��ȯ */
	{
		return SI.Using;
	}
	void addMemory() /**< �뷮 �߰� */
	{
		if (SI.addMemoryCount <= 3)
		{
			SI.Total = 2 * SI.Total;
			SI.addMemoryCount++;
		}
		else
			cout << "3ȸ �̻� �뷮 �߰��� �Ұ����մϴ�" << endl;
	}
	char* getID(int i) /**< ������� ID�� �о�� */
	{
		return UI[i].ID;
	}
	char* getPassword(int i) /**< ������� ��й�ȣ�� �о�� */
	{
		return UI[i].Password;
	}
	char* getAutho(int i) /**< ������� ���ѷ����� �о�� */
	{
		return UI[i].Autho;
	}
	bool getSleep(int i) /**< ������� �޸� ���� ���θ� �о�� */
	{
		return UI[i].Sleep;
	}
	int getLoginCount(int i) /**< �α��� �õ� Ƚ���� ��ȯ */
	{
		return UI[i].LogInCount;
	}
	void addLoginCount(int i) /**< �α��� �õ� Ƚ���� +1 */
	{
		UI[i].LogInCount++;
	}
	void sleepAccount(int i) /**< ������ ������ �޸� ��ȯ */
	{
		UI[i].Sleep = true;
	}
	void saveTempID(int n, char* tempID) /**< ���ο�û ���̵� */
	{
		n = waitingNum;
		waiting[n].ID = tempID;
	}
	void saveTempPass(int n, char* tempPass) /**< ���ο�û �н����� */
	{
		n = waitingNum;
		waiting[n].Password = tempPass;
	}
	void saveTempCitizenNum(int n, char* tempCitizenNum) /**< ���ο�û �ֹι�ȣ */
	{
		n = waitingNum;
		waiting[n].CitizenNum = tempCitizenNum;
	}
	void saveTempAutho(int n, char* tempAutho) /**< ���ο�û ���� */
	{
		n = waitingNum;
		waiting[n].Autho = tempAutho;
	}
	void showWaitList() /**< ������� ���� ���� */
	{
		for (int i = 0; i < sizeof(waiting); i++)
		{
			cout << "<������� ����>" << endl;
			cout << "���̵�: " << waiting[i].ID << endl;
			cout << "�н�����: ****" << endl;
			cout << "�ֹι�ȣ: *************" << endl;
			cout << "��û����: " << waiting[i].Autho << endl;
		}
	}
	void signedUser() /**< ������ ���� ���� */
	{
		for (int i = 0; i < sizeof(UI); i++)
		{
			cout << "<���ε� ����>" << endl;
			cout << "���̵�: " << getID(i) << endl;
			cout << "��й�ȣ: ****" << endl;
			cout << "������: " << getAutho(i) << endl;
			if (getSleep(i) == true)
				cout << "�޸����" << endl;
		}
	}
	void uploadFile() /**< ���� ���ε� */
	{
		cout << "���� ���ε� �Ϸ�" << endl;
	}
	void deleteFile() /**< ���� ���� */
	{
		cout << "���� ���� �Ϸ�" << endl;
	}
	void downloadFile() /**< ���� �ٿ�ε� */
	{
		cout << "���� �ٿ�ε� �Ϸ�" << endl;
	}
	/**

	* @brief		ȸ������ ȭ���� ����ϴ� �޼���

	* @details		ȸ�� ������ �Ϸ��� ������ ������ UserInfo ����ü waiting�� �����Ѵ�. ��ȿ���� ���� ��й�ȣ�� �Է��� �� ���޽����� ����Ѵ�.

	* @param		n ������� ȸ�� ��
		
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
				cout << "��ȿ���� ���� �н�����" << endl;
				continue;
			}
			else
			{
				for (int i = 0; i < sizeof(tempPass); i++)
				{
					if (tempPass[i] < '0' || ('9' < tempPass[i] && tempPass[i] < 'A') || ('Z' < tempPass[i] && tempPass[i] < 'a') || 'z' < tempPass[i])
					{
						cout << "��ȿ���� ���� �н�����" << endl;
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

 * @brief		���� ��带 �����ϴ� Ŭ����

 * @details		���� ���� ���� �� ������ ȭ���� ����ϰ�, ������ ����ϴ� ��ɵ��� �����Ѵ�.

 * @date		2020-09-04

 * @version		0.0.1

*/
class UserMode
{
public:
	/**

	* @brief		����� ��� �α��� ȭ���� ����ϴ� �޼���

	* @details		����ڰ� �Է��� ���̵�� �н������ ��ġ�ϴ� ������ �����ϴ��� Ȯ���Ѵ�.
	
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

	* @brief		�α��ο� �������� �� ȭ���� ����ϴ� �޼���

	* @details		����ڰ� ����� �� �ִ� ��ɵ��� �����Ѵ�.

	*/
	void LogInSuccess()
	{
		int select;

		cout << "���� ��ü�뷮: " << server.getTotal() << endl;
		cout << "���� ���뷮: " << server.getUsing() << endl;
		cout << "��밡�� �뷮" << server.getTotal() - server.getUsing() << endl<<endl;
		cout << "1. ���� ���ε�" << endl;
		cout << "2. ���� ����" << endl;
		cout << "3. ���� �ٿ�ε�" << endl;

		cin >> select;

		switch (select)
		{
		case 1: 
			cout << "���ε��� ������ �����ϼ���" << endl;
			server.uploadFile();
			break;
		case 2:
			cout << "������ ������ �����ϼ���" << endl;
			server.deleteFile();
			break;
		case 3:
			cout << "�ٿ�ε��� ������ �����ϼ���" << endl;
			server.downloadFile();
			break;
		}
	}

private:
	Server server;
};


/**

 * @brief		������ ��带 �����ϴ� Ŭ����

 * @details		������ ���� ���� �� ������ ȭ���� ����ϰ�, �����ڰ� ����ϴ� ��ɵ��� ������ �� �ִ�.

 * @date		2020-09-04

 * @version		0.0.1

*/
class AdminMode
{
public:
	/**

	* @brief		������ �ڵ� �Է� ȭ���� ����ϴ� �޼���

	* @details		�����ڰ� �ùٸ� �ڵ带 �Է��ϸ� ������ ��� ȭ������ �Ѿ��.

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

	* @brief		������ �ڵ� �Է� ������ ������ ȭ���� ����ϴ� �޼���

	* @details		�����ڰ� ����� �� ����� �����Ѵ�.

	*/
	void CodeSuccess()
	{
		int select;

		cout << "1. ������ �ڵ� ����" << endl;
		cout << "2. ������ ���� ����" << endl;
		cout << "3. �ϵ�뷮 �߰�" << endl;
		cout << "4. ������� ���� ����" << endl;
		cout << "5. ���� ���ε�" << endl;
		cout << "6. ���� ����" << endl;
		cout << "7. ���� �ٿ�ε�" << endl;

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
	char* getAdminCode() //�������� �ڵ带 �о��
	{
		return AI.Code;
	}
	void changeCode() //������ �ڵ� ����
	{
		char* temp = new char[CODE_MAX];
		cout << "������ �ڵ�: ";
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

	cout << "1. ����� ���" <<endl<< "2. ������ ���" <<endl<< "3. ȸ������ ��û"<<endl;
	cin >> Select;

	while (true)
	{
		if (Select != 1 || Select != 2 || Select != 3)
			cout << "Wrong Number!" << endl;

		if (Select == 1)
			UM.LoginPage(); //����� ȭ������

		else if (Select == 2)
			AM.AdminPage(); //������ ȭ������

			else if (Select == 3)
			SV.SignUp(waitingNum); //ȸ������ ȭ������
	}
	return 0;
}