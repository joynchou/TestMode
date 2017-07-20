/************************************************************
* ��֯���ƣ�
* �ļ�����: K:\��Ƭ�����\���Ӵ���������\SOFTWARE\TASK\SETUP.C
* ����:     �ܳ��� 
* �汾:    
* ����:     2017/07/18
* ����:		��ʼ�������Ͳ�������ʹ��
* ��ʷ�޸ļ�¼:
* <����> <ʱ��> <�汾 > <����>
* 
***********************************************************/

#include "setup.h"
#include "../HARDWARE/DEVICES/SENSOR/ANGLE/ANGLE.h"
#include "../../HARDWARE/DEVICES/BUTTON/BUTTON.h"	
#include "../../HARDWARE/DEVICES/MOTOR/DC_MOTOR/MOTOR.h"
#include "../../HARDWARE/DEVICES/LED/LED.h"
#include "../../HARDWARE/BSP/USART1.h"
#include "../../HARDWARE/BSP/timer.h"
#include "../../HARDWARE/BSP/GPIO.h"
#include "../../HARDWARE/BSP/delay.h"
#include "../../HARDWARE/BSP/STC15_PWM.h"
#include "../../HARDWARE/DEVICES/MOTOR/STEP_MOTOR/STEP_MOTOR.h"
#include "../../HARDWARE/DEVICES/MOTOR/SERVO/SERVO.h"
#include "../../HARDWARE/DEVICES/DISPLAY/LCD5110/LCD5510_V2.H"
#include "../../HARDWARE/COMMON_HARDWARE/fixedPulser.h"

unsigned char code *str1 = {"Nokia 5510 Test, Haha^_^ I am so glad to see you agian! Do you think so?"};

/*************  ����1��ʼ������ *****************/
/*************************************************
* ��������: void    UART1_init(unsigned long BandRate)
* ����: ����1��ʼ������
* ����: unsigned long BandRate �����ڵĲ����ʣ�������ֵ�����ĸ"L"����ֹ������
* ���: ���ô˺����ᷢ��һ�β������ �� STC15w4k58s4 UART1 is open ��
* ����ֵ: ��
* ����˵��: ��
*************************************************/
void    UART1_init(unsigned long BandRate)
{
	COMx_InitDefine     COMx_InitStructure;
	COMx_InitStructure.UART_Mode = UART_8bit_BRTx;
	COMx_InitStructure.UART_BRT_Use = BRT_Timer2;
	COMx_InitStructure.UART_BaudRate = BandRate;
	COMx_InitStructure.UART_RxEnable = ENABLE;
	COMx_InitStructure.BaudRateDouble = DISABLE;
	COMx_InitStructure.UART_Interrupt = ENABLE;
	COMx_InitStructure.UART_Polity = PolityHigh;
	COMx_InitStructure.UART_P_SW = UART1_SW_P30_P31;
	COMx_InitStructure.UART_RXD_TXD_Short = DISABLE;
	USART_Configuration(USART1, &COMx_InitStructure);
	// PrintString1("STC15w4k58s4's UART1 is open \r\n");   //���ڲ���
}
void test(void)//��������
{    unsigned char i, j, k;
	unsigned char LCD_contrast = 0xc8;


//	stepMotor_Init (STEP_MOTOR_6,1.8f,1,2000);
//	setStepMotorWithRound(STEP_MOTOR_6,5,5);   
//   open_StepMotor(STEP_MOTOR_6);
   LCD5510_Init();
	while(*str1)
	{
		LCD_prints(0, 0, str1++); 
		delay_ms(250); i++;
		LCD_clr_row(0);
	}
	str1 -= i;
	LCD_printsl(0, 0, str1);

	delay_ms(200); 
	LCD_clr_scr();		//����

}
void setup(void)
{
	UART1_init(115200L);
	// timerInit();
	Board_LED_Init();
	Button_config();
	ADC_config(ADC_P10, ADC_540T);
	//LCD1602_Init();
	EA = 1;
  test();

}
