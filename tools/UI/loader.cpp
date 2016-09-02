#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "windows.h"
#include "stdio.h"
#include "fstream.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int send_c100(TMemo *mem,char *s3file);
int connect_c100();
int close_c100();
int compile_asm(char *file_asm,  char *gnude_path);
int saverichedit(char *file, TRichEdit *rich);

HANDLE port; //handle com port
DCB    dcb;  //for com port
COMMTIMEOUTS  ct; //for port
char          buf[255]="";
DWORD         mask=0;
DWORD         bc=0;
char sfile_patch[512],
         asmfile[512];


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


//-----------------------------------------------------
//-----------------------------------------------------
//-----------------------------------------------------
int send_c100(TMemo *mem,char *sfile)
{
/*
mem- лог для сообщений
sfile- пусть к S-файлу

send_c100=1 -ответ от телефона получен, отправлен запрос на переход в downloadmode
send_c100=2 -S файл загружен в телефон
send_c100=0 -ничего от телефона не слышно
*/
 char srun[]="S804400000BB\xD\xA";
 char b1[]="AT**3\xD";
 char bs[1]="~";

 strset(buf,0);
 //читаем порт, читаем аш целых 254 байта
 WaitCommEvent(port,&mask,NULL);
 ReadFile(port,buf,254,&bc,NULL);

 // при нажатии кнопки включения телефон отправляет нам байт 0х81, его и ждем
   if(buf[0]==(char)0x81){
      mem->Lines->Add("Detect 0x81");
      //отправляем телефону 0хЕ7, переводим его в довнлоадмоде
      WriteFile(port,bs,strlen(bs),&bc,NULL);
      // отправляем AT команду, ее я еще не осмыслил но она должна быть
      WriteFile(port,b1,strlen(b1),&bc,NULL);
      return 1;
      }
   //джем ответ от телефона о переходе в довнлоадмоде
   if(strstr(buf,"Download")>0){
      mem->Lines->Add("Change speed and write S-File");
      dcb.BaudRate=115200;
      SetCommState(port,&dcb);
      //load file to phone
      char stroka[1023];
      FILE *sf=fopen(sfile,"r");
      if (sf!=NULL){
         do{
           strset(stroka,0);
           fgets(stroka,1023,sf);
           if(strstr(stroka,"S8040")==0)
           {
                WriteFile(port,stroka,strlen(stroka),&bc,NULL);
                //mem->Text=mem->Text+".";
           }
         }while(!feof(sf));
      //отправляем последнию строку с кодом запуска :З
      WriteFile(port,srun,strlen(srun),&bc,NULL);
      fclose(sf);}else {mem->Lines->Add("err Open Loading File...");}
      //end load
      return 2;
      }
   return 0;}
//-----------------------------------------------------
//-----------------------------------------------------
//-----------------------------------------------------

//-----------------------------------------------------
//-----------------------------------------------------
//-----------------------------------------------------
int connect_c100()
{
/*
0-подключили порт
1-не подключили
*/
   port=CreateFile("COM1",GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_EXISTING,0,NULL);
   if(port==INVALID_HANDLE_VALUE) {return 0;  }

   SetupComm(port,65558, 65558);
   GetCommState(port,&dcb);

  dcb.BaudRate=38400;
  dcb.StopBits=0;
  dcb.Parity=0;
  dcb.ByteSize=8;

  ct.ReadIntervalTimeout=10;
  ct.ReadTotalTimeoutMultiplier=ct.ReadTotalTimeoutConstant=0;
  ct.WriteTotalTimeoutMultiplier=ct.WriteTotalTimeoutConstant=0;

   SetCommState(port,&dcb);
   SetCommTimeouts(port,&ct);
   SetCommMask(port,EV_RXCHAR);
   PurgeComm(port,PURGE_RXCLEAR);

return 1;}
//-----------------------------------------------------
//-----------------------------------------------------
//-----------------------------------------------------

//-----------------------------------------------------
//-----------------------------------------------------
//-----------------------------------------------------
int close_c100()
{
  CloseHandle(port);
  return 0;}
//-----------------------------------------------------
//-----------------------------------------------------
//-----------------------------------------------------

//-----------------------------------------------------
//-----------------------------------------------------
//-----------------------------------------------------
int compile_asm(char *file_asm, char *gnude_path)
{
/*
file_asm-пусть к исходнику
gnude_patch-пасположение компилятора
*/

char file_patch[1023],file_name[1023],me_patch[1023];

// чистим строки строки
for(int j=0;j<=1023;j++){file_patch[j]=0;file_name[j]=0;};
//тут и чуть дальше виделяем тольку путь к фалу
// и имя файла, для создания там следующих файлов
strcpy(file_patch,file_asm);
    for (int i=strlen(file_asm);i>=1;i--)
    {
        if(file_asm[i]==0x5c)
        {
                file_patch[i+1]=0x0; //< получам путь
                for (unsigned ii=1;ii<=strlen(file_asm);ii++)
                {
                        file_name[ii-1]=file_asm[i+ii];
                        if (file_asm[i+ii+1]=='.'){ii=strlen(file_asm);}
                }
                i=1;
        }
    }

AnsiString    file_obj="",file_out="",file_s="",file_bin="",tmp;
//тут создаем имена файлов
file_obj=file_patch;
file_obj=file_obj+file_name +".obj";
file_out=file_patch;
file_out=file_out+file_name+".out";
file_bin=file_patch;
file_name[7]=0;
file_bin=file_bin+file_name+".bin";
file_s=file_patch;
file_s=file_s+file_name+".s";

tmp="-mthumb-interwork -k -EL -W -mcpu=arm7tdmi -o "+file_obj+" "+file_asm;
ShellExecute(0,"open","arm-elf-as.exe",tmp.c_str(),gnude_path,0);

tmp=file_obj+" --entry=0x400000  -Ttext 0x400000 -o "+file_out;
Sleep(10);
ShellExecute(0,"open","arm-elf-ld.exe",tmp.c_str(),gnude_path,0);

tmp="-O binary "+file_out+" "+file_bin;
Sleep(100);
ShellExecute(0,"open","arm-elf-objcopy.exe",tmp.c_str(),gnude_path,0);

tmp=file_bin+" "+file_s+" /2 /O0x400000 /h";
Sleep(10);
ShellExecute(0,"open","bin2mot.exe",tmp.c_str(),"e:\\test2\\",0);

strcpy(sfile_patch,file_s.c_str());
return 0;
}
//-----------------------------------------------------
//-----------------------------------------------------
//-----------------------------------------------------


//-----------------------------------------------------
//-----------------------------------------------------
//-----------------------------------------------------
int saverichedit(char *savfile, TRichEdit *rich)
{
/*
savfile-пусть к сохраняемому файлу
rich- компонент с текстом richedit

0-ошибка содания файла
1-успешно сохранен
*/
FILE *nf;
if((nf=fopen(savfile,"wt"))==NULL){return 0;}else
{
   fprintf(nf,"%s",rich->Text.c_str());
   fclose(nf);
}
return 1;}
//-----------------------------------------------------
//-----------------------------------------------------
//-----------------------------------------------------



void __fastcall TForm1::compileSfile1Click(TObject *Sender)
{ //загрузка  последнего откомпилированого или открытого файла
FILE *tst;
if ((tst=fopen(sfile_patch,"r"))==NULL)
{
        Log->Lines->Add("S-File not found...");
}else{
        fclose(tst);
        if (connect_c100()==1)
        {
                Log->Clear();
                Log->Lines->Add("Start Listen PORT...");
                do{
                        Sleep(10);
                }while(send_c100(Log,sfile_patch)!=2);
                Log->Lines->Add("Load Complete!");
                close_c100();
         }else{
                Log->Lines->Add("Error open COM port...");
         }
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::openSFile1Click(TObject *Sender)
{ //загрузка  открытого файла
if (connect_c100()==1)
{
        OpenDialog1->FileName="";
        OpenDialog1->Title="Open S-File";
        OpenDialog1->FilterIndex=2 ;
        OpenDialog1->Execute();
        Log->Clear();
        if(OpenDialog1->FileName=="")
        {
                Log->Lines->Add("user abort");
        }else{
                Log->Lines->Add("File select:"+OpenDialog1->FileName);
                Log->Lines->Add("Start Listen PORT...");
                do{
                        Sleep(10);
                }while(send_c100(Log,OpenDialog1->FileName.c_str())!=2);
                Log->Lines->Add("sending ok!");

        }
        close_c100();
}else{
        Log->Lines->Add("Error open COM port...");
}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::open1Click(TObject *Sender)
{
OpenDialog1->Title="Open .asm Code";
OpenDialog1->FilterIndex=1;
OpenDialog1->Execute();
strcpy(asmfile,OpenDialog1->FileName.c_str());
RichEdit1->Text="";
char stroka[1024];
FILE *af=fopen(asmfile,"r");
if (af!=NULL)
        {
         do{
           strset(stroka,0);
           fgets(stroka,255,af);
           RichEdit1->Text=RichEdit1->Text+stroka;
         }while(!feof(af));
        fclose(af);}else {Log->Lines->Add("err Open asm File...");
        }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------


void __fastcall TForm1::save1Click(TObject *Sender)
{
if(saverichedit(asmfile,RichEdit1)==1){Log->Lines->Add("save ok ;)");};
}
//---------------------------------------------------------------------------

void __fastcall TForm1::saveas1Click(TObject *Sender)
{
char nfile[1023]="";

SaveDialog->Title="Saving ASM code";
SaveDialog->Execute();
if(SaveDialog->FileName!="")
{
        strcpy(nfile,SaveDialog->FileName.c_str());
        if (saverichedit(nfile,RichEdit1)==1){ strcpy(asmfile,nfile);}
        Log->Lines->Add("save ok!");
}

}
//---------------------------------------------------------------------------


void __fastcall TForm1::compile1Click(TObject *Sender)
{
if(saverichedit(asmfile,RichEdit1)==1)
{
        Log->Lines->Add("save ok ;)");
        compile_asm(asmfile,"c:\\gnude\\bin\\");
};
}
//---------------------------------------------------------------------------

void __fastcall TForm1::new1Click(TObject *Sender)
{
if((saverichedit(asmfile,RichEdit1)==1) || (asmfile[0]==0))
{
        Log->Lines->Add("save ok, close.");
        SaveDialog->Execute();
        strcpy(asmfile,SaveDialog->FileName.c_str());
        RichEdit1->Text="";
        saverichedit(asmfile,RichEdit1);
        Log->Lines->Add("create ok:");
        Log->Lines->Add(asmfile);
};

}
//---------------------------------------------------------------------------

void __fastcall TForm1::close1Click(TObject *Sender)
{
saverichedit(asmfile,RichEdit1);
RichEdit1->Text="";
strset(asmfile,0);
}
//---------------------------------------------------------------------------

