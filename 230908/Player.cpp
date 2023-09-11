#include "pch.h"
#include "Player.h"
#include "Weapon.h"
#include "Armor.h"

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
	cout << "===== 플레이어 정보 =====" << endl << endl;

	cout << "이름: " << Get_Name() << endl;
	cout << "레벨: " << Get_Level() << endl;
	cout << "직업: " << Get_JobString() << endl;
	cout << "체력: " << Get_Hp() << " / " << Get_MaxHp() << endl;
	cout << "공격력: " << Get_Attack() << endl;
	cout << "경험치: " << Get_Exp() << " / " << Get_NeedExp() << endl;
	cout << "보유골드: " << Get_Gold() << " G" << endl;
	if(m_pArmor)
		cout << "장착 갑옷: " << m_pArmor->Get_Name() << endl;
	if(m_pWeapon)
		cout << "장착 무기: " << m_pWeapon->Get_Name() << endl;
	cout << endl;
}

void CPlayer::Initialize()
{
	cout << "===== 캐릭터 생성 =====" << endl << endl;
	system("cls");

	Input_Name();

	while (true)
	{
		system("cls");
		cout << "===== 직업 선택 =====" << endl << endl;
		cout << "1. 전사" << endl;
		cout << "2. 법사" << endl;
		cout << "3. 도적" << endl;

		Select_Job();

		switch (m_iJob)
		{
		case WARRIOR:
			Set_JobString("전사");
			Set_MaxHp(100);			Set_Attack(10);
			break;

		case MAGE:
			Set_JobString("법사");
			Set_MaxHp(50);			Set_Attack(15);
			break;

		case THIEF:
			Set_JobString("도적");
			Set_MaxHp(80);			Set_Attack(12);
			break;

		default:
			cout << "보기에 없는 입력입니다. 다시 입력하세요. " << endl << endl;
			system("pause");
			continue;
		}

		Set_Hp(Get_MaxHp());		Set_Level(1);
		Set_NeedExp(40);			Set_Gold(1000);
		Set_Exp(0);

		m_pInven = new CInventory();

		cout << "캐릭터 생성 완료" << endl << endl;
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
			cout << "장비의 타입이 무기가 아닙니다." << endl << endl;

			return false;
		}
		else if (m_pWeapon)
		{
			int iTemp;
			m_pInven->Add_Item(m_pWeapon);
			Set_MinAtt(iTemp = m_pWeapon->Get_Attack());

			m_pWeapon = _pWeapon;
			Set_AddAtt(m_pWeapon->Get_Attack());

			cout << "무기 " << m_pWeapon->Get_Name() << "을 장착했습니다." << endl << endl;

			cout << "공격력이" << m_pWeapon->Get_Attack() - iTemp << "증가하였습니다." << endl << endl;

			return true;
		}
		else
		{
			m_pWeapon = _pWeapon;
			Set_AddAtt(m_pWeapon->Get_Attack());

			cout << "무기 " << m_pWeapon->Get_Name() << "을 장착했습니다." << endl << endl;

			cout << "공격력이" << m_pWeapon->Get_Attack() << "증가하였습니다." << endl << endl;
			return true;
		}
	}
	else
	{
		if (m_pWeapon)
		{
			if(m_pInven->Add_Item(m_pWeapon))
				m_pWeapon = nullptr;
		}
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
			cout << "장비의 타입이 갑옷이 아닙니다." << endl << endl;

			return false;
		}
		else if (m_pArmor)
		{
			int iTemp;
			m_pInven->Add_Item(m_pArmor);
			Set_MinMaxHp(iTemp = m_pArmor->Get_Hp());



			m_pArmor = _pArmor;
			Set_AddMaxHp(m_pArmor->Get_Hp());

			cout << "방어구 " << m_pArmor->Get_Name() << "을 장착했습니다." << endl << endl;

			cout << "체력이" << m_pArmor->Get_Hp() - iTemp << "증가하였습니다." << endl << endl;
			return true;
		}
		else
		{
			m_pArmor = _pArmor;
			Set_AddMaxHp(m_pArmor->Get_Hp());

			cout << "방어구 " << m_pArmor->Get_Name() << "을 장착했습니다." << endl << endl;

			cout << "체력이" << m_pArmor->Get_Hp() << "증가하였습니다." << endl << endl;
			return true;
		}
	}
	else
	{
		if (m_pArmor)
		{
			if (m_pInven->Add_Item(m_pArmor))
				m_pArmor = nullptr;
		}
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

		cout << "1. 아이템 장착" << endl;
		cout << "2. 돌아가기" << endl;
		cout << "선택: ";
		cin >> iChoice;

		cout << endl;

		switch (iChoice)
		{
		case 1:
			cout << "아이템 번호를 입력하세요" << endl;
			cout << "선택: ";
			cin >> iIdx;
			iIdx -= 1;
			iter += iIdx;

			Equipitem = (*iter);

			iType = (dynamic_cast<CItem*>(Equipitem))->Get_Type();

			if (iType >= NORMAL_WEAPON && iType < WEAPON_END)
			{
				if (Equip_Wepon(Equipitem))
				{
					iter = m_pInven->Get_Inven().erase(iter);

					cout << "무기를 장착하였습니다." << endl << endl;
					break;
				}
			}

			else if (iType >= NORMAL_ARMOR && iType < ARMOR_END)
			{
				if (Equip_Armor(Equipitem))
				{
					iter = m_pInven->Get_Inven().erase(iter);

					cout << "갑옷을 장착하였습니다." << endl << endl;
					break;
				}
			}

			else
				cout << "아이템 장착에 실패하였습니다." << endl << endl;
			break;

		case 2:
			cout << "돌아갑니다.." << endl << endl;
			return;

		default:
			cout << "보기에 없는 입력입니다. 다시 입력하세요." << endl << endl;

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

void CPlayer::Set_AddAtt(int _iAdd)
{
	if (0 > _iAdd)
		return;
	Set_Attack(Get_Attack() + _iAdd);
}

void CPlayer::Set_MinAtt(int _iMin)
{
	if (Get_Attack() < _iMin)
		Set_Attack(0);
	else
	{
		Set_Attack(Get_Attack() - _iMin);
	}
}

void CPlayer::Set_AddMaxHp(int _iAdd)
{
	if (0 > _iAdd)
		return;
	else
	{
		Set_MaxHp(Get_MaxHp() + _iAdd);
	}
}

void CPlayer::Set_MinMaxHp(int _iMin)
{
	if (_iMin > Get_MaxHp())
		Set_MaxHp(0);
	else
	{
		Set_MaxHp(Get_MaxHp() - _iMin);
	}
}

void CPlayer::LoadData()
{
	FILE* fLoad = nullptr;
	errno_t err = fopen_s(&fLoad, "../data/save.dat", "rb");
	if (0 == err)
	{
		cout << "파일 개방 성공" << endl << endl;

		int iAtt(0), iHp(0), iMaxHp(0), iExp(0), iNeedExp(0), iLevel(0), iJob(0), iGold(0);

		int iType(0), iDura(0);

		bool bEquipWp(false), bEquipAmr(false);

		int iLen = 0;
		char* pString = nullptr;
		fread(&iLen, sizeof(int), 1, fLoad);
		pString = new char[iLen + 1];
		fread(pString, sizeof(char), iLen + 1, fLoad);

		Set_Name(pString);
		delete[] pString;
		pString = nullptr;

		fread(&iLen, sizeof(int), 1, fLoad);
		pString = new char[iLen + 1];
		fread(pString, sizeof(char), iLen + 1, fLoad);

		Set_JobString(pString);
		delete[] pString;
		pString = nullptr;

		fread(&iAtt, sizeof(int), 1, fLoad);
		fread(&iHp, sizeof(int), 1, fLoad);
		fread(&iMaxHp, sizeof(int), 1, fLoad);
		fread(&iExp, sizeof(int), 1, fLoad);
		fread(&iNeedExp, sizeof(int), 1, fLoad);
		fread(&iLevel, sizeof(int), 1, fLoad);
		fread(&iJob, sizeof(int), 1, fLoad);
		fread(&iGold, sizeof(int), 1, fLoad);

		Set_Attack(iAtt);
		Set_Hp(iHp);
		Set_MaxHp(iMaxHp);
		Set_Exp(iExp);
		Set_NeedExp(iNeedExp);
		Set_Level(iLevel);
		Set_Job(iJob);
		Set_Gold(iGold);

		fread(&bEquipWp, sizeof(bool), 1, fLoad);
		fread(&bEquipAmr, sizeof(bool), 1, fLoad);

		if (bEquipWp)
		{
			fread(&iType, sizeof(int), 1, fLoad);
			fread(&iDura, sizeof(int), 1, fLoad);

			CObj* loadWp = new CWeapon(iType);
			dynamic_cast<CItem*>(loadWp)->Initialize();
			dynamic_cast<CItem*>(loadWp)->Set_Dura(iDura);

			m_pWeapon = loadWp;
		}

		if (bEquipAmr)
		{
			fread(&iType, sizeof(int), 1, fLoad);
			fread(&iDura, sizeof(int), 1, fLoad);

			CObj* loadArmor = new CArmor(iType);
			dynamic_cast<CItem*>(loadArmor)->Initialize();
			dynamic_cast<CItem*>(loadArmor)->Set_Dura(iDura);

			m_pArmor = loadArmor;
		}

		int iInvenCnt(0);

		fread(&iInvenCnt, sizeof(int), 1, fLoad);

		m_pInven = new CInventory;

		for (int iIdx = 0; iIdx < iInvenCnt; ++iIdx)
		{
			fread(&iType, sizeof(int), 1, fLoad);
			fread(&iDura, sizeof(int), 1, fLoad);

			if (NORMAL_WEAPON <= iType && WEAPON_END > iType)
			{
				CObj* loadWp = new CWeapon(iType);
				dynamic_cast<CItem*>(loadWp)->Initialize();
				dynamic_cast<CItem*>(loadWp)->Set_Dura(iDura);

				m_pInven->Get_Inven().push_back(loadWp);
			}
			else if (NORMAL_ARMOR <= iType && ARMOR_END > iType)
			{
				CObj* loadArmor = new CArmor(iType);
				dynamic_cast<CItem*>(loadArmor)->Initialize();
				dynamic_cast<CItem*>(loadArmor)->Set_Dura(iDura);

				m_pInven->Get_Inven().push_back(loadArmor);
			}
		}

		cout << "파일 불러오기 완료" << endl << endl;

		fclose(fLoad);
		return;
	}

	else
	{
		cout << "파일 개방 실패" << endl << endl;

		fclose(fLoad);
		return;
	}
}

void CPlayer::SaveData()
{
	FILE* fSave = nullptr;
	errno_t err = fopen_s(&fSave, "../data/save.dat", "wb");
	if (0 == err)
	{
		cout << "파일 개방 성공" << endl << endl;

		int iAtt(0), iHp(0), iMaxHp(0), iExp(0), iNeedExp(0), iLevel(0), iJob(0), iGold(0);
		int iType(0), iDura(0);

		bool bEquipWp(false), bEquipAmr(false);

		int iLen = Get_Name().Get_Len();
		fwrite(&iLen, sizeof(int), 1, fSave);
		fwrite(Get_Name().Get_String(), sizeof(char), iLen + 1, fSave);

		iLen = Get_JobString().Get_Len();
		fwrite(&iLen, sizeof(int), 1, fSave);
		fwrite(Get_JobString().Get_String(), sizeof(char), iLen + 1, fSave);

		iAtt = Get_Attack();
		fwrite(&iAtt, sizeof(int), 1, fSave);

		iHp = Get_Hp();
		fwrite(&iHp, sizeof(int), 1, fSave);

		iMaxHp = Get_MaxHp();
		fwrite(&iMaxHp, sizeof(int), 1, fSave);

		iExp = Get_Exp();
		fwrite(&iExp, sizeof(int), 1, fSave);

		iNeedExp = Get_NeedExp();
		fwrite(&iNeedExp, sizeof(int), 1, fSave);

		iLevel = Get_Level();
		fwrite(&iLevel, sizeof(int), 1, fSave);

		iJob = Get_Job();
		fwrite(&iJob, sizeof(int), 1, fSave);

		iGold = Get_Gold();
		fwrite(&iGold, sizeof(int), 1, fSave);

		if (m_pWeapon)
			bEquipWp = true;

		fwrite(&bEquipWp, sizeof(bool), 1, fSave);

		if (m_pArmor)
			bEquipAmr = true;

		fwrite(&bEquipAmr, sizeof(bool), 1, fSave);

		if (bEquipWp)
		{
			iType = dynamic_cast<CItem*>(m_pWeapon)->Get_Type();
			iDura = dynamic_cast<CItem*>(m_pWeapon)->Get_Dura();

			fwrite(&iType, sizeof(int), 1, fSave);
			fwrite(&iDura, sizeof(int), 1, fSave);
		}

		if (bEquipAmr)
		{
			iType = dynamic_cast<CItem*>(m_pArmor)->Get_Type();
			iDura = dynamic_cast<CItem*>(m_pArmor)->Get_Dura();

			fwrite(&iType, sizeof(int), 1, fSave);
			fwrite(&iDura, sizeof(int), 1, fSave);
		}

		int iInvenCnt = m_pInven->Get_Inven().size();
		fwrite(&iInvenCnt, sizeof(int), 1, fSave);

		for (int iIdx = 0; iIdx < iInvenCnt; ++iIdx)
		{
			iType = dynamic_cast<CItem*>(m_pInven->Get_Inven()[iIdx])->Get_Type();
			iDura = dynamic_cast<CItem*>(m_pInven->Get_Inven()[iIdx])->Get_Dura();

			fwrite(&iType, sizeof(int), 1, fSave);
			fwrite(&iDura, sizeof(int), 1, fSave);
		}

		cout << "저장 완료!" << endl << endl;

		fclose(fSave);

		return;
	}

	else
	{
		cout << "파일 개방 실패" << endl << endl;

		fclose(fSave);
		return;
	}
}

void CPlayer::Level_Up()
{
	int iMaxHp;
	int iAttack;

	cout << "레벨업!" << endl << endl;

	switch (m_iJob)
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

	cout << "최대체력 " << iMaxHp << "상승" << endl;
	cout << "공격력 " << iAttack << "상승" << endl;

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

	cout << "이름: ";
	cin >> name;

	Set_Name(name);
}

void CPlayer::Select_Job()
{
	int iInput(0);
	cin >> iInput;
	m_iJob = iInput;
}
