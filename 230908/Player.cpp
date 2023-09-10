#include "pch.h"
#include "Player.h"

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Release()
{
	Safe_Delete<CInventory*>(m_pInven);
	Safe_Delete<CObj*>(m_pArmor);
	Safe_Delete<CObj*>(m_pWeapon);
}

void CPlayer::Render() const
{
	cout << "===== �÷��̾� ���� =====" << endl << endl;

	cout << "�̸�: " << Get_Name() << endl;
	cout << "����: " << Get_Level() << endl;
	cout << "����: " << Get_JobString() << endl;
	cout << "ü��: " << Get_Hp() << " / " << Get_MaxHp() << endl;
	cout << "���ݷ�: " << Get_Attack() << endl;
	cout << "����ġ: " << Get_Exp() << " / " << Get_NeedExp() << endl;
	cout << "�������: " << Get_Gold() << " G" << endl << endl;
}

void CPlayer::Initialize()
{
	cout << "===== ĳ���� ���� =====" << endl << endl;
	system("cls");

	Input_Name();

	while (true)
	{
		system("cls");
		cout << "===== ���� ���� =====" << endl << endl;
		cout << "1. ����" << endl;
		cout << "2. ����" << endl;
		cout << "3. ����" << endl;

		Select_Job();

		switch (m_iJob)
		{
		case WARRIOR:
			Set_JobString("����");
			Set_MaxHp(100);			Set_Attack(10);
			break;

		case MAGE:
			Set_JobString("����");
			Set_MaxHp(50);			Set_Attack(15);
			break;

		case THIEF:
			Set_JobString("����");
			Set_MaxHp(80);			Set_Attack(12);
			break;

		default:
			cout << "���⿡ ���� �Է��Դϴ�. �ٽ� �Է��ϼ���. " << endl << endl;
			system("pause");
			continue;
		}

		Set_Hp(Get_MaxHp());		Set_Level(1);
		Set_NeedExp(40);			Set_Gold(100);
		Set_Exp(0);

		m_pInven = new CInventory();

		cout << "ĳ���� ���� �Ϸ�" << endl << endl;
		system("pause");
		return;
	}
}

bool CPlayer::Equip_Wepon(CObj* _pWeapon)
{
	if (_pWeapon)
	{
		int iType = dynamic_cast<CItem*>(_pWeapon)->Get_Type();
		if (iType < NORMAL_WEAPON && iType > WEAPON_END)
		{
			cout << "����� Ÿ���� ���Ⱑ �ƴմϴ�." << endl << endl;
			
			return false;
		}
		if(m_pInven->Add_Item(m_pWeapon))
			m_pWeapon = _pWeapon;

		return true;
	}
	else
	{
		cout << "�� ������ �����ϴ�." << endl << endl;
		return false;
	}
}

bool CPlayer::Equip_Armor(CObj* _pArmor)
{
	if (_pArmor)
	{
		int iType = dynamic_cast<CItem*>(_pArmor)->Get_Type();
		if (iType < NORMAL_ARMOR && iType > ARMOR_END)
		{
			cout << "����� Ÿ���� ������ �ƴմϴ�." << endl << endl;

			return false;
		}
		if (m_pInven->Add_Item(m_pArmor))
			m_pArmor = _pArmor;

		return true;
	}
	else
	{
		cout << "�� ������ �����ϴ�." << endl << endl;
		return false;
	}
}

void CPlayer::Inventory()
{
	int iChoice(0);
	int iIdx(0);
	int iType(0);
	CObj* Equipitem = nullptr;
	vector<CObj*>::iterator iter;
	while (true)
	{
		iter = m_pInven->Get_Inven().begin();

		m_pInven->Render();

		cout << "1. ������ ����" << endl;
		cout << "2. ���ư���" << endl;
		cout << "����: ";

		switch (iChoice)
		{
		case 1:
			cout << "������ ��ȣ�� �Է��ϼ���" << endl;
			cout << "����: ";
			cin >> iIdx;

			iter += iIdx - 1;

			Equipitem = (*iter);

			iType = (dynamic_cast<CItem*>(Equipitem))->Get_Type();

			if (iType >= NORMAL_WEAPON && iType < WEAPON_END)
			{
				if (Equip_Wepon(Equipitem))
				{
					m_pInven->Get_Inven().erase(iter);

					cout << "���⸦ �����Ͽ����ϴ�." << endl << endl;
					break;
				}
			}
			if (iType >= NORMAL_ARMOR && iType < ARMOR_END)
			{
				if (Equip_Armor(Equipitem))
				{
					m_pInven->Get_Inven().erase(iter);

					cout << "������ �����Ͽ����ϴ�." << endl << endl;
					break;
				}
			}

			cout << "������ ������ �����Ͽ����ϴ�." << endl << endl;
			break;

		case 2:
			cout << "���ư��ϴ�.." << endl << endl;
			return;

		default:
			cout << "���⿡ ���� �Է��Դϴ�. �ٽ� �Է��ϼ���." << endl << endl;

			system("pause");
			continue;
		}
		system("pause");
	}
	

}

void CPlayer::Set_AddExp(int _iAdd)
{
	if (_iAdd < 0)
	{
		return;
	}

	else if (Get_NeedExp() <= Get_Exp() + _iAdd)
	{
		Level_Up();
	}

	else
		Set_Exp(Get_Exp() + _iAdd);
}

void CPlayer::Set_MinExp(int _iMin)
{
	if (_iMin < 0)
	{
		return;
	}
	else if (0 >= Get_Exp() - _iMin)
	{
		Set_Exp(0);
	}
	else
		Set_Exp(Get_Exp() - _iMin);
}

void CPlayer::Set_AddHp(int _iAdd)
{
	if (0 >= _iAdd)
	{
		return;
	}
	else if (Get_Hp() + _iAdd >= Get_MaxHp())
	{
		Set_Hp(Get_MaxHp());
	}
	else
		Set_Hp(Get_Hp() + _iAdd);
}

void CPlayer::Set_AddGold(int _iAdd)
{
	if (0 >= _iAdd)
		return;

	else
		Set_Gold(Get_Gold() + _iAdd);
}

void CPlayer::Set_MinGold(int _iMin)
{
	if (0 >= _iMin)
		return;

	else if (Get_Gold() < _iMin)
		Set_Gold(0);

	else
		Set_Gold(Get_Gold() - _iMin);
}

void CPlayer::Set_LoadData(String _Name, String _JobString)
{
	Set_Name(_Name);
	Set_JobString(_JobString);
}

void CPlayer::Set_SaveData()
{
	Set_Name(nullptr);
	Set_JobString(nullptr);
}

void CPlayer::Level_Up()
{
	int iMaxHp;
	int iAttack;
	
	cout << "������!" << endl << endl;

	switch(m_iJob)
	{
	case WARRIOR:
		iMaxHp = 30;		iAttack = 2;
		break;

	case MAGE:
		iMaxHp = 10;		iAttack = 4;
		break;

	case THIEF:
		iMaxHp = 20;		iAttack = 3;
		break;
	}

	cout << "�ִ�ü�� " << iMaxHp << "���" << endl;
	cout << "���ݷ� " << iAttack << "���" << endl;

	Set_Attack(Get_Attack() + iAttack);
	Set_MaxHp(Get_MaxHp() + iMaxHp);

	Set_Hp(Get_MaxHp());
	Set_Level(Get_Level() + 1);
	Set_NeedExp(Get_NeedExp() + 20);
	Set_Exp(0);
	system("pause");
}

void CPlayer::Input_Name()
{
	String name;

	cout << "�̸�: ";
	cin >> name;

	Set_Name(name);
}

void CPlayer::Select_Job()
{
	int iInput(0);
	cin >> iInput;
	m_iJob = iInput;
}
