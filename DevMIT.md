#pragma comment(lib, "version.lib")
-------------------------------------

외부 라이브러리 읽기

````
static CString GetFileVersion(LPCTSTR lpszFilePath)
{
	VS_FIXEDFILEINFO info ;
	CString version ;
	if(GetFileInfo(lpszFilePath, &info))
	{
		version.Format(_T("%d.%d.%d.%d"), 
			(info.dwFileVersionMS >> 16) & 0x0000ffff, (info.dwFileVersionMS >> 0) & 0x0000ffff,
			(info.dwFileVersionLS >> 16) & 0x0000ffff, (info.dwFileVersionLS >> 0) & 0x0000ffff) ;
	}

	return version ;
}
````
구조체 VS_FIXEDFILEINFO에 들어있는 정보를 이용하여 파일의 버전을 구한다.

OnPaint 는 필요 없는부분 건드리지 않는다

void CDevMITPinPadDlg::OnBtPassword()
---------------------------------------

비밀변호를 요청하는 함수

````
KillAllTimer() ;
````

모든 타이머를 0으로 초기화

````
if(nPWMode <= 13 || (15 <= nPWMode && nPWMode <= 32))
	{
		m_ctrlPassword.SetWindowText("");
		int	ret ;
		switch(nPWMode)
		{
		case 16 :	
					SoundControl(FALSE) ;
#ifdef	HYUNDAI
					ret = ReadPinPadPasswordMM(0, CString2i(m_pwLengthMin, 4), CString2i(m_pwLengthMax, 4), 1+ (m_autoenter.GetCheck() ? 0x10 : 0x20)) ; // Repeat 사용 안함 (기본=1)
#else
					ret = ReadPinPadPasswordMM(0, CString2i(m_pwLengthMin, 4), CString2i(m_pwLengthMax, 4), 1+ (m_autoenter.GetCheck() ? 8 : 0)) ; // Repeat 사용 안함 (기본=1)
#endif					
					SoundControl(TRUE) ;
					SoundPlay(0) ;
					break ;
		case 17 :	
					SoundControl(FALSE) ;
#ifdef	HYUNDAI
					ret = ReadPinPadPasswordMM(2, CString2i(m_pwLengthMin, 4), CString2i(m_pwLengthMax, 4), 1+ (m_autoenter.GetCheck() ? 0x10 : 0x20)) ; // Repeat 사용 안함 (기본=1)
#else
					ret = ReadPinPadPasswordMM(2, CString2i(m_pwLengthMin, 4), CString2i(m_pwLengthMax, 4), 1+ (m_autoenter.GetCheck() ? 8 : 0)) ; // Repeat 사용 안함 (기본=1)
#endif
					SoundControl(TRUE) ;
					SoundPlay(1) ;
					break ;
		case 18 :	
					SoundControl(FALSE) ;
#ifdef	HYUNDAI
					ret = ReadPinPadPasswordMM(0, CString2i(m_pwLengthMin, 4), CString2i(m_pwLengthMax, 4), 1+ (m_autoenter.GetCheck() ? 0x10 : 0x20)) ; // Repeat 사용 안함 (기본=1)
#else
					ret = ReadPinPadPasswordMM(0, CString2i(m_pwLengthMin, 4), CString2i(m_pwLengthMax, 4), 1+ (m_autoenter.GetCheck() ? 8 : 0)) ; // Repeat 사용 안함 (기본=1)
#endif
					SoundControl(TRUE) ;
					SoundPlay(2) ;
					break ;
		case 19 :	
					SoundControl(FALSE) ;
#ifdef	HYUNDAI
					ret = ReadPinPadPasswordMM(2, CString2i(m_pwLengthMin, 4), CString2i(m_pwLengthMax, 4), 1+ (m_autoenter.GetCheck() ? 0x10 : 0x20)) ; // Repeat 사용 안함 (기본=1)
#else
					ret = ReadPinPadPasswordMM(2, CString2i(m_pwLengthMin, 4), CString2i(m_pwLengthMax, 4), 1+ (m_autoenter.GetCheck() ? 8 : 0)) ; // Repeat 사용 안함 (기본=1)
#endif
					SoundControl(TRUE) ;
					SoundPlay(3) ;
					break ;
		case 22 :
#ifdef	HYUNDAI
					ret = ReadPinPadPasswordMM(nPWMode, CString2i(m_pwLengthMin, 4), CString2i(m_pwLengthMax, 4), 1+ (m_autoenter.GetCheck() ? 0x10 : 0x20)) ; // Repeat 사용 안함 (기본=1)
#else
					ret = ReadPinPadPasswordMM(nPWMode, CString2i(m_pwLengthMin, 4), CString2i(m_pwLengthMax, 4), 1+ (m_autoenter.GetCheck() ? 8 : 0)) ; // Repeat 사용 안함 (기본=1)
#endif
					break ;
		default :
#ifdef	HYUNDAI
					ret = ReadPinPadPasswordMM(nPWMode, CString2i(m_pwLengthMin, 4), CString2i(m_pwLengthMax, 4), 1+ (m_autoenter.GetCheck() ? 0x10 : 0x20)) ; // Repeat 사용 안함 (기본=1)
#else
					ret = ReadPinPadPasswordMM(nPWMode, CString2i(m_pwLengthMin, 4), CString2i(m_pwLengthMax, 4), 1+ (m_autoenter.GetCheck() ? 8 : 0)) ; // Repeat 사용 안함 (기본=1)
#endif
					break ;
		}
````

nPWMode가 16, 18중 하나일 경우 0모드 비밀번호 입력

17, 19중 하나일경우 2모드 비밀번호 재입력

22, 그외에 숫자일경우 nPWMode가 가리키는 모드로 입력

다만 사운드는 모두 다르므로 쓰임새에 따라 정확한 모드를 

````
		if(ret==SUCCESS)
		{
			SetTimer(TIMER_PASSWORD_ID, TIMER_PASSWORD_INTERVAL, NULL);	// 비밀번호 얻어오기 위해서 timer 돌리면서 check
			m_ctrlStatus.SetWindowText(PW_WAIT_MSG);
		}
		else if(ret == HW_ERROR)		m_ctrlStatus.SetWindowText(HW_ERROR_MSG);
		else if(ret == CONNECTION_FAIL)	m_ctrlStatus.SetWindowText(CONNECTION_FAIL_MSG);
		else if(ret == FUNCTION_FAIL)	m_ctrlStatus.SetWindowText(FUNCTION_FAIL_MSG);	
		else if(ret == 0)	
		{
			m_ctrlStatus.SetWindowText("실패 - 비밀번호 4자리 입력해 주세요");			
			ResetPinPad();
		}
````

SetTimer를 돌리면서 체크함으로서 비밀번호를 얻는다

만약 ret이 1이 아닐경우엔 에러발생하며 0일경우 비밀번호 4자리 재입력 나머지경우엔 각 에러와 사유가 출력된다

void CDevMITPinPadDlg::OnBtDoublePassword()
-----------------------------------

위의 함수와 매우 유사하나 비밀번호를 2번 입력한다.


OnBtPasswordCancel()
----------------------

CancelPinPad();함수를 실행하여 사용중이던 핀패드기능을 캔슬하는 함수

OnButtonReset()
-----------------------

ResetPinPad();함수를 실행하여 사용중이던 내용을 완전히 초기화하는 함수

OnAsync(WPARAM nRet, LPARAM lParam)
--------------------------------------

고객이 입력한 비밀번호를 얻어오기 위한 함수

````
if(ret==SUCCESS) && (g_nLength!=0))
````

입력받은 패스워드의 길이가 0이면 바로 에러출력

````
			g_password[g_nLength] = 0x00 ;
			m_strPassword = g_password;
			m_ctrlPassword.SetWindowText(m_strPassword) ;
			m_ctrlStatus.SetWindowText(SUCCESS_MSG) ;
````
g_password가 고객이 입력한 수의 배열이며 마지막은 0x00

그 값을 m_strPassword에 넘겨주고 출력한다.

````
    else if((ret== SUCCESS) && (g_nLength==0))	m_ctrlStatus.SetWindowText(PW_FAIL_MSG);
		else if(ret == NOOPERATION)				 	m_ctrlStatus.SetWindowText(NOOPERATION_MSG);
		else if(ret == WAIT)					 	m_ctrlStatus.SetWindowText(PASSWORD_WAIT_MSG);
		else if(ret == TIMEOUT)						m_ctrlStatus.SetWindowText(TIMEOUT_MSG);
		else if(ret == HW_ERROR)					m_ctrlStatus.SetWindowText(HW_ERROR_MSG);
		else if(ret == CONNECTION_FAIL)				m_ctrlStatus.SetWindowText(CONNECTION_FAIL_MSG);
		else if(ret == FUNCTION_FAIL)				m_ctrlStatus.SetWindowText(FUNCTION_FAIL_MSG);
		else if(ret == ICCARD_FAIL)					m_ctrlStatus.SetWindowText(ICCARD_FAIL_MSG);
		else 
		{
			m_ctrlStatus.SetWindowText(PW_FAIL_MSG);
		}
````

ret에 문제가있거나 고객이 비밀번호를 입력하지않을경우, 혹은 그외 기타 등등의경우엔 에러발생



OnBtTrack2()
-----------------------


시작하면 KillALLTimer(); 함수릀 실행시켜 값을 초기화한다.

````
int	ret = ReadPinPadMSR(2) ;
		if(ret == SUCCESS)
		{
			SetTimer(TIMER_MSR_ID, TIMER_PASSWORD_INTERVAL, NULL);		// 비밀번호 얻어오기 위해서 timer 돌리면서 check
			m_ctrlStatus.SetWindowText(MSR_WAIT_MSG) ;
		}
````

MSR방식으로 비밀번호를 입력시킨 다음 그 값을 읽는다.

정상적으로 진행됬다면 SetTimer를 돌리쳐 체크해서 비밀번호를 얻어온다.

OnBtTrack2() 와 OnBtTrack3()의 차이는 ISO Track 2를 사용하는지 ISO Track3을 사용하는지의 차이이다.

GetICCardInfo()
----------------

IC카드의 정보를 가져오는 함수

````
	if(SUCCESS != InitPinPad())				return "InitPinPad 실패!!" ;
	if(SUCCESS != CancelPinPad())			return "CancelPinPad 실패!!" ;
````

InitPinPad() 또는 CancelPinPad()가 에러가난다면 바로 강제종료된다

````
int nResult = PinPad_SMC_PowerUp(ID1_CARD, cOutputData, &nOutputLen, &cModuleResult) ;
if(!(cModuleResult == 0x00 && nResult == SUCCESS))	return "IC Card PowerUp 실패!!"	;
````

nResult를 선언한다 nResult는 PinPad_SMC_PowerUp의 리턴값이며

리턴을 제대로 받지 못하거나 cMouduleResult에 이상이 있을경우 함수가 강제종료된다

````
	cOutputData[nOutputLen] = 0x00 ;
	ret.Append((const char *)cOutputData) ;
	
	memset(cOutputData, 0x00, sizeof(cOutputData)); nOutputDataLen = 0; cStatus = 0x00; nSW = 0;
````

IC카드로부터 읽은 데이터의 끝자리엔 null값을 넣는다.

ret에 IC카드로부터 읽은 데이터값을 추가한다.

응답데이터값의 메모리를 0x00으로 세팅하고 그외에 사용한값을 0으로 초기화한다

````
		////////////////////0   1   2   3   4   5   6   7   8   9   0   1   2
		memcpy(cInputData, "\x00\xA4\x04\x00\x07\xD4\x10\x65\x09\x90\x00\x10", nInputDataLen = 12) ;
		memset(cOutputData, 0x00, sizeof(cOutputData)); nOutputDataLen = sizeof(cOutputData) ;
		smc_result = PinPad_SMC_ISOInput(0x00, cInputData[0], cInputData[1], cInputData[2], cInputData[3], cInputData[4],
									&cInputData[5], nInputDataLen-5, cOutputData, &nOutputDataLen,
									&cStatus, &nSW) ;
````

cInputData부터 12바이트만큼 \x00\xA4\x04\x00\x07\xD4\x10\x65\x09\x90\x00\x10를 복사한다

cOutputData는 0x00으로 채워넣는다

smc_result에 일반IC카드기준으로 데이터값인 cInputData의 배열과 길이, 응답받는데이터인 cOutputData와 길이, 응답코드를 넣는다

이 내용은 값만다른 비슷한방식을 3번사용한다

````
if(cOutputData[0x0E] == 0x10 && nOutputDataLen >= 0x0F+0x10)
		{
			cOutputData[0x0F+0x10] = 0x00 ;
			ret.Append((const char *)(&cOutputData[0x0F])) ;
		}
````

조건이 맞을경우 cOutputData의 일부분을 0x00으로 강제한다

그리고  ret에 0x00을 추가한다

````
if(cOutputData[0x04] == 0x1A && nOutputDataLen >= (0x05+0x1A))
		{
			cOutputData[0x05+0x1A] = 0x00 ;
			ret.Append((const char *)(&cOutputData[0x05])) ;
		}
````

바로 위의 내용과 값과 주소가 조금 다를뿐 방식이 그대로다

````
for(int acc = 1; acc <= 10; acc++) {
memcpy(cInputData, "\x00\xB2\x01\x14\x40", nInputDataLen = 5) ;
cInputData[2] = (unsigned char)acc ;
memset(cOutputData, 0x00, sizeof(cOutputData)); nOutputDataLen = sizeof(cOutputData) ;
smc_result = PinPad_SMC_ISOOutput(0x00, cInputData[0], cInputData[1], cInputData[2], cInputData[3], cInputData[4],
								cOutputData, &nOutputDataLen,
								&cStatus, &nSW) ;
````

위쪽의 메모리셋팅하는것과 같은 방식이다

다만 cInputData에 반복문이 몇번째인지가 대입된다.

````
	if(nOutputDataLen >= 56)
			if((memcmp(cOutputData,"\xC1\x3E\x01\xB0\x15\x90", 6) == 0)
			|| (memcmp(cOutputData,"\xC1\x3E\x01\x00\x15\x90", 6) == 0))
			{
				memset(track_data, 0x00, sizeof(track_data)) ;
				for(int i = 0; i < 53; i++)
				{
					track_data[i*2+0] = 0x30 | ((cOutputData[3+i] >> 4) & 0x0F) ;
					track_data[i*2+1] = 0x30 | ((cOutputData[3+i] >> 0) & 0x0F) ;
				}
					
				track_data[105] = 0x00 ;
				ret.Append((const char *)(&track_data[1])) ;
				PinPad_SMC_PowerDown(0x00, &cModuleResult) ;
				return ret ; 
			}
		}
	PinPad_SMC_PowerDown(0x00, &cModuleResult) ;
	return ret ; 
}

    
````
OutputData의 길이가 56보다 크면서 

cOutputData부터 시작하는 6의 메모리가 \xC1\x3E\x01\xB0\x15\x90 또는 \xC1\x3E\x01\x00\x15\x90 일때

track_data의 메모리를 0x00으로 초기화한다음

track_data과 cOutputData에 각각에 맞는 |값을 구하고

105번째는 0x00으로 초기화한다

ret에는 &track_data배열의 [1]값을 추가하고 PinPad_SMC_PowerDown함수를 작동한 뒤 ret을 리턴한다

조건이 맞지않다면 track_data는 무시한채로 PinPad_SMC_PowerDown함수를 작동한 뒤 ret을 리턴한다

OnTimer(UINT_PTR nIDEvent) 
--------------

nIDevent에 들어가는 값에따라 기능이 전혀다름
````
	switch(nIDEvent)
	{
	case TIMER_CONNECTED_ID :
		ret = isConnected(0) ;
		if(ret== SUCCESS)	m_isConnected.SetWindowText("연결됨") ;
		else				m_isConnected.SetWindowText("연결안됨") ;
		break ;
````

nIDevent가 900일 경우에 작동

ret의값을 isConnected(0) 으로 초기화

````
case TIMER_PASSWORD_ID:
		
		ret = ReadPinPadReturn(&Dev_id, &Cmd, password, &nLength);					// 비밀번호 얻어오기 시도 중
		if((ret==SUCCESS) && (nLength!=0) && Dev_id == 1)
		{
			m_strPassword = password;
			m_ctrlPassword.SetWindowText(m_strPassword);
			m_ctrlStatus.SetWindowText(SUCCESS_MSG);
		}
else if((ret== SUCCESS) && (nLength==0))	m_ctrlStatus.SetWindowText(PW_FAIL_MSG);
else if(ret == NOOPERATION)				 	m_ctrlStatus.SetWindowText(NOOPERATION_MSG);
else if(ret == WAIT)					 	m_ctrlStatus.SetWindowText(PASSWORD_WAIT_MSG);
else if(ret == TIMEOUT)						m_ctrlStatus.SetWindowText(TIMEOUT_MSG);
else if(ret == HW_ERROR)					m_ctrlStatus.SetWindowText(HW_ERROR_MSG);
else if(ret == CONNECTION_FAIL)				m_ctrlStatus.SetWindowText(CONNECTION_FAIL_MSG);
else if(ret == FUNCTION_FAIL)				m_ctrlStatus.SetWindowText(FUNCTION_FAIL_MSG);
else if(ret == ICCARD_FAIL)					m_ctrlStatus.SetWindowText(ICCARD_FAIL_MSG);
else if(ret == 0)							m_ctrlStatus.SetWindowText("비밀번호 입력수 부족");

if(ret != WAIT) 
KillTimer(TIMER_PASSWORD_ID) ;


break;
		
````

nIDevent가 901일때 작동

입력한 비밀번호를 얻어오는 함수  ResetPinPadReturn 을 실행

m_strPasswd에 패스워드 값을 넣고 리턴값을  값을 윈도우에 나타낸다 

````
case TIMER_MSR_ID:
		
	ret = ReadPinPadReturn(&Dev_id, &Cmd, track_data, &nLength);		
	if((ret == SUCCESS) && Dev_id == 2)
	{				
		CString strLength;
		if(Cmd == 2)
		{
			strLength.Format("%d",nLength);
			m_ctrlMsrTrack2Length.SetWindowText(strLength);
			if(nLength) m_ctrlMsrTrack2.SetWindowText((LPCTSTR)track_data);
			else m_ctrlMsrTrack2.SetWindowText(" ");
		}
		else if(Cmd == 3)
		{
			strLength.Format("%d",nLength);
			m_ctrlMsrTrack3Length.SetWindowText(strLength);
			if(nLength) m_ctrlMsrTrack3.SetWindowText((LPCTSTR)track_data);
			else m_ctrlMsrTrack3.SetWindowText(" ");
		}
		
		m_ctrlStatus.SetWindowText(SUCCESS_MSG);
	}		
	else if((ret== SUCCESS) && (nLength==0))m_ctrlStatus.SetWindowText(MSR_FAIL_MSG) ;
	else if(ret == WAIT)					m_ctrlStatus.SetWindowText(MSR_WAIT_MSG) ;
	else if(ret == TIMEOUT)					m_ctrlStatus.SetWindowText(TIMEOUT_MSG) ;
	else if(ret == HW_ERROR)				m_ctrlStatus.SetWindowText(HW_ERROR_MSG) ;
	else if(ret == CONNECTION_FAIL)			m_ctrlStatus.SetWindowText(CONNECTION_FAIL_MSG) ;
	else if(ret == FUNCTION_FAIL)			m_ctrlStatus.SetWindowText(FUNCTION_FAIL_MSG) ;
	else if(ret == TRACK_FAIL)				m_ctrlStatus.SetWindowText(TRACK_FAIL_MSG) ;
	else if(ret == ICCARDINSERT)			m_ctrlStatus.SetWindowText(ICCARDINSERT_MSG) ;
	else if(ret == 0)
	{
		ret=ResetPinPad();
		if (ret ==0 ) CancelPinPad();
					
		m_ctrlStatus.SetWindowText("리턴 0");
		Beep(1000, 1000);
	}
		tmp.Format( "ReadPinPadReturn = %d", ret);
	OutputDebugString(tmp);
	
	if(ret != WAIT) 
		KillTimer(TIMER_MSR_ID);			
	break;
````

nIDevent가 902일때 작동

입력한 비밀번호를 얻어오는 함수  ResetPinPadReturn 을 실행

가cmd2거나 3일경우 입력받은 비밀번호와 길이를 저장

````
case TIMER_ACCOUNT_ID:
		
	ret = ReadPinPadReturn(&Dev_id, &Cmd, &AccountIndex, &nLength);
	if(ret == SUCCESS)
	{
		CString strIndex;
		strIndex.Format("%d", AccountIndex);
		m_accountCtrl.SetWindowText(strIndex);
		m_ctrlStatus.SetWindowText("계좌 선택 OK");
	}
	else if(ret == NOOPERATION)
	{
		m_ctrlStatus.SetWindowText("계좌 선택이 취소 또는 함수를 잘못 호출하였습니다. 처음부터 다시 시도해 주세요");
	}
	else if(ret == WAIT)
	{
		m_ctrlStatus.SetWindowText("계좌 선택 대기중");
	}
	else
	{
		m_ctrlStatus.SetWindowText("계좌 선택 실패");
	}
	
	if(ret != WAIT) 
		KillTimer(TIMER_ACCOUNT_ID);
	break;
````

nIDevent가 903일때 작동

선택한 계좌의값을 나타내주는 함수 ReadPinPadReturn 작동

정상적으로 작동되씅ㄹ경우 strIndex에 선택계좌값을 대입하고

그 값을 윈도우에 나타냄

````
case TIMER_IC_ID:
	ret = ReadPinPadReturn(NULL, NULL, NULL, NULL);
		  
	if(ret == SUCCESS)				m_ctrlStatus.SetWindowText(SUCCESS_MSG);
	else if(ret == TIMEOUT)			m_ctrlStatus.SetWindowText(TIMEOUT_MSG);
	else if(ret == HW_ERROR)		m_ctrlStatus.SetWindowText(HW_ERROR_MSG);
	else if(ret == CONNECTION_FAIL)	m_ctrlStatus.SetWindowText(CONNECTION_FAIL_MSG);
	else if(ret == FUNCTION_FAIL)	m_ctrlStatus.SetWindowText(FUNCTION_FAIL_MSG);
	else if(ret == TRACK_FAIL)		m_ctrlStatus.SetWindowText(TRACK_FAIL_MSG);
	else if(ret == NOOPERATION)		m_ctrlStatus.SetWindowText(NOOPERATION_MSG);
	else if(ret == WAIT)			m_ctrlStatus.SetWindowText(IC_WAIT_MSG);
	
	if(ret != WAIT)	
		KillTimer(TIMER_IC_ID);
	break;
````
nIDevent가 904일때 작동하며

아무일도 일어나지 않은채로 KillTimer만 작동함


````
case TIMER_STRESS_PASSWORD_ID:
	{
		CString tmp ;
		tmp.Format("PIN반복(%d/%d)", ++stress_counter, m_StressTimes) ;
		m_btPasswordStress.SetWindowText(tmp) ;
		this->OnBtPassword() ;
		if(stress_counter == m_StressTimes)
		{
			KillTimer(TIMER_STRESS_PASSWORD_ID) ;
			m_btPasswordStress.SetWindowText("비밀번호반복요청") ;
			stress_counter = 0 ;
		}
	}
	break ;
````

nIDevent 911일때  작동

stress_counter현재 횟수와 m_StressTimes총 횟수ㅡㄹ 이용하여 비밀번호를 반복 요청하는 코드

tmp에 반복적으로 stress_counter/m_StressTimes를 대입

stress_counter와 m_StressTimes가 같아지면 KillTimer가 작동하고 stress_counter는 0으로 초기화

````
case TIMER_STRESS_DOUBLE_PASSWORD_ID:
	{
		CString tmp ;
		tmp.Format("PIN2반복(%d/%d)", ++stress_counter, m_StressTimes) ;
		m_btDoublePasswordStress.SetWindowText(tmp) ;
		this->OnBtDoublePassword() ;
		if(stress_counter == m_StressTimes)
		{
			KillTimer(TIMER_STRESS_DOUBLE_PASSWORD_ID) ;
			m_btDoublePasswordStress.SetWindowText("PIN2반복요청") ;
			stress_counter = 0 ;
		}
	}
	break ;
````

nIDevent 916번일때 작동

위의 코드와 완전이 동일하되 횟수가 반복횟수가다르다

````
case TIMER_STRESS_ICCARD_ID:
	{
		CString info = GetICCardInfo() ;
		CString tmp ;
		tmp.Format("IC반복(%d/%d)", ++stress_counter, m_StressTimes) ;
		m_btICStress.SetWindowText(tmp) ;
		FILE *fp = fopen("C:\\MIT2000\\ic_stress.csv", "a+t") ;
		if(fp)
		{
			fprintf(fp,"%d, %s\n", stress_counter, (const char *)info) ;
			fclose(fp) ;
		}
		if(stress_counter == m_StressTimes)
		{
			KillTimer(TIMER_STRESS_ICCARD_ID) ;
			m_btICStress.SetWindowText("IC카드읽기반복") ;
			stress_counter = 0 ;
		}
		m_ctrlStatus.SetWindowText("C:\\MIT2000\\ic_stress.csv에 기록중");
	}
	break ;
````

nIDevent 912일때 작동

info에 GetICCardInfo()의 리턴값을 대입하고

tmp에 stress_counter/m_stressTimes를 대입한다

*fp에 fopen으로 ic_stress.csv를 오픈하는 형태로 선언한다

fp에 그리고 stress_counter와 (const char*)info를 출력시킨다

stress_counter와 m_stressTimes가 같을때 KillTimer를 실행하고 stress_counter를 0으로 초기화한다

````
case TIMER_STRESS_SIGN_ID:
	{
		CString tmp ;
		tmp.Format("서명반복(%d/%d)", ++stress_counter, m_StressTimes) ;
		m_btSignStress.SetWindowText(tmp) ;
		this->OnBnClickedSign() ;
		if(stress_counter == m_StressTimes)
		{
			KillTimer(TIMER_STRESS_SIGN_ID) ;
			m_btSignStress.SetWindowText("서명반복요청") ;
			stress_counter = 0 ;
		}
	}
	break ;
````
nIDevent 913일때 작동

911, 916과 매우 흡사하지만 OnbnclickedSign을 실행하여 서명을 요구한다는점만 다르다

````
case TIMER_STRESS_MSR_ID:
	{
		CString tmp ;
		tmp.Format("MSR반복(%d/%d)", ++stress_counter, m_StressTimes) ;
		m_btMSRStress.SetWindowText(tmp) ;
		this->OnBtTrack2() ;
		if(stress_counter == m_StressTimes)
		{
			KillTimer(TIMER_STRESS_MSR_ID) ;
			m_btMSRStress.SetWindowText("MSR반복요청") ;
			stress_counter = 0 ;
		}
	}
	break ;
````

nIDevent 914일때 작동

마찬가지로 반복요청하는 코드이며 OnBtTrack2()를 작동

MSR을 반복 요청한다

````
case TIMER_WRITE_ICCARD_ID:
	{
		int info = this->WriteTest() ;
		CString tmp ;
		tmp.Format("IC반복(%d/%d)", ++stress_counter, m_StressTimes) ;
		m_btICWrite.SetWindowText(tmp) ;
		FILE *fp = fopen("C:\\MIT2000\\ic_write.csv", "a+t") ;
		if(fp)
		{
			fprintf(fp,"%d, %d\n", stress_counter, info) ;
			fclose(fp) ;
		}
		if(info != 19)
		{
			KillTimer(TIMER_WRITE_ICCARD_ID) ;
			m_btICWrite.SetWindowText("IC카드쓰기반복오류!!") ;
			stress_counter = 0 ;
		}
		if(stress_counter == m_StressTimes)
		{
			KillTimer(TIMER_WRITE_ICCARD_ID) ;
			m_btICWrite.SetWindowText("IC카드쓰기반복") ;
			stress_counter = 0 ;
		}
		m_ctrlStatus.SetWindowText("C:\\MIT2000\\ic_write.csv에 기록중");
	}
	break ;
}
````
IDevent 915일때 작동

912번과 흡사하게 작동한다

WriteTest()를 실행하여 IC카드 쓰기를 반복한다

OnSoundindexTx() 
--------------------

````
int		nResult = 0;

	UpdateData(TRUE);

	nResult = SoundPlay(m_soundIndex);
	if(nResult == SUCCESS)	
		m_ctrlStatus.SetWindowText("SoundPlay Success.");
	else					
		m_ctrlStatus.SetWindowText("SoundPlay Fail.");
````

SoundPlay를 실행시키고

작동에 성공하면 Success를 실패시 Fail을 출력한다

void CDevMITPinPadDlg::IcCardModeCheck(unsigned char flag) 
------------------------------

ret을 0으로초기화하고 KillTimer 까지 작동시킨다

ReadICCardInsertCheck의 리턴값을 ret에 대입하고

정상적으로 작동한다면 "IC 카드 삽입 유무 확인" 을 WindowText 로 세팅한다

그리고 flag의 값 상태에 따라 알맞는 내용을 출력한다

:OnMessageClearSet()
------------------

````
	GetDlgItem(IDC_ET_PASSWORD)->SetWindowText("") ;
	GetDlgItem(IDC_ET_MSR_TRACK2)->SetWindowText("");
	GetDlgItem(IDC_ET_MSR_TRACK2_LENGTH)->SetWindowText("");
	GetDlgItem(IDC_ET_MSR_TRACK3)->SetWindowText("");
	GetDlgItem(IDC_ET_MSR_TRACK3_LENGTH)->SetWindowText("");

	// RichEdit Control
	m_strApduResponse.Empty();
	m_ctrlApduResponse.SetWindowText(m_strApduResponse);
	m_ctrlApduResponse.SetSel(m_strApduResponse.GetLength(), -1);
	m_ctrlApduResponse.LineScroll(m_ctrlApduResponse.GetLineCount(), 0);
	m_ctrlApduResponse.SendMessage(WM_VSCROLL, SB_BOTTOM, NULL);

	m_ctrlStatus.SetWindowText("");
	UpdateData(FALSE);
````

세팅한 값을 초기화 하는 함수


OnButtonApduPowerup()
-----------------

````
{
	char	cOutputData[300] = {0};
	int		nOutputLen = 0;
	char	cStatus = 0x00;
	int		ret = 0;
	BYTE nCardType = m_ctrlCardtype.GetCurSel();

	ret = InitPinPad(); // CancelPinPad가 더욱 확실함.
	ret = SMC_PowerUp(nCardType, cOutputData , &nOutputLen , &cStatus);

	if(ret == 1 && cStatus == 0 )
	{
		m_ctrlStatus.SetWindowText(CString("IC Card ATR PowerUp 통신 성공"));
		AddApduRcvdString(false, (unsigned char *)cOutputData, nOutputLen) ;
	}
	else
	{
		if(cStatus == (char)0xFB)	m_ctrlStatus.SetWindowText("IC Card(Chip) 없슴!!") ;
		else						m_ctrlStatus.SetWindowText("IC Card ATR PowerUp 실패!!") ;
	}
}
````

InitPinPAD()와 SMC_PowerUp을 차례로 작동시킨다

SMC_PowerUp이 정상적으로 작동하고 cStatus가 0일때 

WindowText를 변경시키고 AddApudRcvdString함수를 작동한다

실패시 WindowText만 변경하고 다른 함수는 사용하지않는다

OnButtonApduPowerdown() 
----------------------

````
	char	cStatus = 0x00;
	BYTE nCardType = m_ctrlCardtype.GetCurSel();
	int ret = SMC_PowerDown(nCardType, &cStatus);
	if(ret == 1 && cStatus == 0 )
		m_ctrlStatus.SetWindowText(CString("IC Card ATR Power Down  통신 성공!!"));
	else
		m_ctrlStatus.SetWindowText(CString("IC Card ATR Power Down 통신 실패!!"));
````

응답코드를 0x00로 초기화하고 카드타입을 설정한다음

SMC_PowerDown을 함수를 실행한다

결과에따라 성공 또는 실패를 SetWindowText 한다

OnButtonApduSend() 
------------

````
	char szApduCmd[300] = {0,};
	strcpy(szApduCmd, m_strApduCommand.GetBuffer(0)) ;
````

보내는 APDU문자열을 선언하고 거기에 m_strAdpuCommand.GetBuffer를 복사시킨다

````
for(int i = 0, j = 0; i < 300; i++)
	{
		if('0'<= szApduCmd[i] && szApduCmd[i] <= '9')		szApduCmd[j++] = szApduCmd[i] ;
		else if('A'<= szApduCmd[i] && szApduCmd[i] <= 'F')	szApduCmd[j++] = szApduCmd[i] ;
		else if('a'<= szApduCmd[i] && szApduCmd[i] <= 'f')	szApduCmd[j++] = szApduCmd[i] ;
		else if(szApduCmd[i] == 0x00)						szApduCmd[j++] = szApduCmd[i] ;
		else												continue ;

		if(szApduCmd[i] == 0x00)							break ;
	}
````

문자열 szApduCmd[]에 해당되는 APDU문자열을 대입시킨다

0x00이 나온다면 문자열이 끝난다.

````
	char szApduRes[300] = {0,};	

	WORD nSW = 0x0000;
	BYTE nCardType = m_ctrlCardtype.GetCurSel();	//	#define	ID1_CARD	0x00	
````

받는 APDU문자열 szApduRes를 선언

코드값 nSW와 카드타입도 같이 선언

````
{
	unsigned char send[300] ;
	int send_len = String2Bin(szApduCmd, send, strlen(szApduCmd)) ;
	AddApduRcvdString(true, send, send_len) ;
}
````

문자열 send 를 선언하고

String2Bin의 리턴값을 send_len에 대입한다음

 AddAdpuRcvdString함수를 실행한다
 
 ````
nResult = SMC_ApduCmdString(nCardType, szApduCmd, szApduRes, &nSW);
	if(nResult != 0x01)
	{
		m_ctrlStatus.SetWindowText("IC Card ATR APDU 명령 실패!!");
	}
	else
	{
		unsigned char recv[300] ;
		int recv_len = String2Bin(szApduRes, recv, strlen(szApduRes)) ;
		AddApduRcvdString(false, recv, recv_len, nSW) ;
		CString str ;
		str.Format("IC Card ATR APDU 명령 성공(SW1:0x%02X,SW2:0x%02X)", (nSW >> 8) & 0x00FF, (nSW >> 0) & 0x00FF);
		m_ctrlStatus.SetWindowText(str);
	} 
 ````
 
 nResult에 SMC_ApduCmdString의 리턴값을 대입하고
 
 에러가 없다면 SetWindowText로 성공과 값을 나타낸다
 
AddApduRcvdString
---------------------

````
return this->AddApduRcvdString(send, (const unsigned char *)lpszItem, len, sw) ;
````

AddApduRcvdString을 실행하고 그 값을 리턴값으로 설정한다.


````
	if(send)	m_strApduResponse.AppendFormat("---Send[%d]---\n", len) ;
	else		m_strApduResponse.AppendFormat("---Recv[%d]---SW:%04X\n", len, sw) ;
	m_strApduResponse += DisplayHexa(lpszItem, len) ;
	m_ctrlApduResponse.SetWindowText(m_strApduResponse);

````

보내는 apdu엔 보내는값을 받는거엔 받는값을 저장한다

m_strApduResponse에 DiplayHexa의 값을 추가시키고 SetWindowText한다


KillAllTimer()
-----------------

````
	KillTimer(TIMER_PASSWORD_ID);
	KillTimer(TIMER_MSR_ID);
	KillTimer(TIMER_ACCOUNT_ID);
	KillTimer(TIMER_IC_ID);
	KillTimer(TIMER_SIGN_ID) ;
	KillTimer(TIMER_CAMERA_ID) ;
	KillTimer(TIMER_CAMERA_DISPLAY) ;
	return TRUE;
````

타이머 값을 전부초기화하고 1을 리턴하는 함수

OnCheckBuzzer()
---------------

````
int ret = 0;
unsigned char Ptr[100] = {0,};

UpdateData(TRUE);

ret = BuzzerControl(m_bBuzzerOn);
````

ret과 Ptr을 초기화하고

BuzzerControl 함수를 실행

````
if(ret)
{
	if(m_bBuzzerOn == TRUE)
		sprintf((char *)Ptr,"Buzzer On 설정되었습니다. %d", m_bBuzzerOn);
	else if(m_bBuzzerOn == FALSE)
		sprintf((char *)Ptr,"Buzzer Off 설정되었습니다. %d", m_bBuzzerOn);
}
else
{
	if(m_bBuzzerOn == TRUE)
		sprintf((char *)Ptr,"Buzzer On 설정 실패입니다. %d", m_bBuzzerOn);
	else if(m_bBuzzerOn == FALSE)
		sprintf((char *)Ptr,"Buzzer Off 설정 실패입니다. %d", m_bBuzzerOn);
	m_bBuzzerOn = m_bBuzzerOn ? FALSE : TRUE;	// Invert
}
````

ret이 정상적으로 작동할경우 m_BuzzerOn의 상태에따라 Buzzer의 On,Off상태가 변화함

ret이 정상적으로 동작하지 않았다면 설정 실패를 출력

OnCheckSound()
------------

````
int ret = 0;
	unsigned char Ptr[100] = {0,};
	
	UpdateData(TRUE);
	
	ret = SoundControl(m_bSoundOn);
	if(ret)
	{
		if(m_bSoundOn == TRUE)
			sprintf((char *)Ptr,"Sound On 설정되었습니다. %d", m_bSoundOn);
		else if(m_bSoundOn == FALSE)
			sprintf((char *)Ptr,"Sound Off 설정되었습니다. %d", m_bSoundOn);
	}
	else
	{
		if(m_bSoundOn == TRUE)
			sprintf((char *)Ptr,"Sound On 설정 실패입니다. %d", m_bSoundOn);
		else if(m_bSoundOn == FALSE)
			sprintf((char *)Ptr,"Sound Off 설정 실패입니다. %d", m_bSoundOn);

		m_bSoundOn = m_bSoundOn ? FALSE : TRUE;	// Invert
	}
	m_ctrlStatus.SetWindowText((const char *)Ptr);
	UpdateData(FALSE);	
````

Buzzer와 전체적으로 동일한 코드

BuzzerControl 대신 SoundeControl을 사용한것을 제외하면

On,Off나 설정 성공, 실패등은 모두 같은 방식이다 


OnButtonPasswordAsync()
-------------------------

````
UpdateData(TRUE) ;

nPWMode = toInteger(m_PasswordType, 0);
KillAllTimer();
````

nPWMode에 toInteger의 리턴값을 대입하고

KillAllTimer를 실행시켜 타이머를 초기화한다

````
if(nPWMode <= 9 || nPWMode == 12 || nPWMode == 13 || nPWMode == 15 || nPWMode == 20 || nPWMode == 21)
{
	int nRet = InitPinPad();
	if(SUCCESS != CancelPinPad())	return;
	//SetPasswdDisplayMode(_0toStarDisplay) ;
	SetPasswdDisplayMode(this->m_dispType) ;
}
````
nPWMode가 9이하거나, 12, 13, 15, 20, 21 중 하나일경우

InitPinPad();함수를 실행시키고

CancelPinPad()함수가 정상작동하지 않는다면 해당함수 바로 리턴

CanCelPinPad가 정상작동한다면 SetPasswdDisplayMode에 m_dispType내용 삽입

````
if(nPWMode <= 13 || nPWMode == 15 || nPWMode == 20 || nPWMode == 21)
{
int	ret = GetPinPadPasswordMM(nPWMode, CString2i(m_pwLengthMin, 4), CString2i(m_pwLengthMax, 4), 1, m_hWnd, WM_GETPINPADPASSWORDMM);
	m_ctrlPassword.SetWindowText("");
	if(ret==SUCCESS)				m_ctrlStatus.SetWindowText(PW_WAIT_MSG);
	else if(ret == HW_ERROR)		m_ctrlStatus.SetWindowText(HW_ERROR_MSG);
	else if(ret == CONNECTION_FAIL)	m_ctrlStatus.SetWindowText(CONNECTION_FAIL_MSG);
	else if(ret == FUNCTION_FAIL)	m_ctrlStatus.SetWindowText(FUNCTION_FAIL_MSG);		
}
````

nPWMode의 값이 13보다 작거나, 15, 20. 21중 하나일경우

GetPinPadPasswordMM함수를 실행하고

함수가 정상적으로 실행되면 비밀번호 입력을 대기받는다

정상이 아닐경우 에러 메세지 출력

Logf
----------

````
if(fp != NULL)
{
	SYSTEMTIME  stime;
	GetLocalTime(&stime);
	fprintf(fp, "%02d:%02d:%02d.%03d",stime.wHour, stime.wMinute, stime.wSecond, stime.wMilliseconds);
	
	va_list args;
	va_start(args, fmt) ;
	vfprintf(fp, fmt, args) ;
	va_end(args) ;
}
````
시간함수 SYSTEMTIME을 선언

GetLocalTime으로 시간을 습득하고

시간에 대한 정보를 시단위부터 밀리초단위까지 출력
