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
{ 
	unsigned char code *str1 = {"Nokia 5510 Test, Haha^_^ I am so glad to see you agian! Do you think so?"};
	unsigned char code *str2 = {"I Love You AVR"};
  unsigned char i, j, k;
	unsigned char LCD_contrast = 0xc8; 
	while(*str1)
	{
		LCD_prints(0, 0, str1++); 
		delay_ms(250); i++;
		LCD_clr_row(0);
	}
	str1 -= i;
	LCD_printsl(0, 0, str1);

	delay_ms(200);delay_ms(200);delay_ms(200);delay_ms(200);delay_ms(200);; delay_ms(200);delay_ms(200);delay_ms(200);delay_ms(200);delay_ms(200);;
	LCD_clr_scr();		//����
	for(i = 0; i < 14; i++) {LCD_printc(i, 2, str2[i]); delay_ms(250);}

	delay_ms(200);delay_ms(200);delay_ms(200);delay_ms(200);delay_ms(200);;
	LCD_prints(0, 3, ">--(*^_^*)--<");
	delay_ms(200);delay_ms(200);delay_ms(200);delay_ms(200);delay_ms(200);;

	LCD_prints(0, 0, "Blank Test ");
	delay_ms(200);delay_ms(200);delay_ms(200);delay_ms(200);delay_ms(200);;
	LCD_show_blank;		//�հײ���
	delay_ms(200);delay_ms(200);delay_ms(200);delay_ms(200);delay_ms(200);;
	LCD_prints(0, 0, "Normal Test");
	LCD_show_normal;	//�ָ�����
	delay_ms(200);delay_ms(200);delay_ms(200);delay_ms(200);delay_ms(200);;
	LCD_prints(0, 0, "Black Test ");
	delay_ms(200);delay_ms(200);delay_ms(200);delay_ms(200);delay_ms(200);;
	LCD_show_black;		//ȫ�ڼ�⻵��
	delay_ms(200);delay_ms(200);delay_ms(200);delay_ms(200);delay_ms(200);;
	LCD_show_normal;	//�ָ�����
	delay_ms(200);delay_ms(200);delay_ms(200);delay_ms(200);delay_ms(200);;
	LCD_prints(0, 0, "Inverse Test");
	LCD_show_inverse;	//��ɫ
	delay_ms(200);delay_ms(200);delay_ms(200);delay_ms(200);delay_ms(200);;
	LCD_prints(0, 0, "Normal again");
	LCD_show_normal;	//�ָ�����
	delay_ms(200);delay_ms(200);delay_ms(200);delay_ms(200);delay_ms(200);;
	LCD_clr_scr();		//����
	delay_ms(200);delay_ms(200);delay_ms(200);delay_ms(200);delay_ms(200);;
	
	i = 0; j = 0; k =0;
	while(k++ < 101)	//ASCII�ַ�����
	{ 
		LCD_printc(i, j, k + 32); 
		delay_ms(250); 
		i++; if(i == 14) {i = 0; j++;}
		if(j == 6) j = 0;
	}
	
	LCD_prints(2, 1, "Alexi2008");
	while(1)				//�Աȶ��������
	{
		LCD_write_cmd(0x23);//����ģʽ, ˮƽѰַ, ��չָ��	

		for(i = 0; i < 10; i++) {LCD_contrast++; LCD_write_cmd(LCD_contrast); delay_ms(250);}
		for(i = 0; i < 20; i++) {LCD_contrast--; LCD_write_cmd(LCD_contrast); delay_ms(250);}
		for(i = 0; i < 10; i++) {LCD_contrast++; LCD_write_cmd(LCD_contrast); delay_ms(250);}
	}


}
void setup(void)
{
	UART1_init(115200L);
  //timerInit();
	Board_LED_Init();
	Button_config();
	//ADC_config(ADC_P10, ADC_540T);
	LCD5510_Init();
  test();

}

