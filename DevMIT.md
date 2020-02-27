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
