#include<stdio.h>
#include<stdlib.h>
#include"valuser.h"
/*

                                                                                                                                                                                                     
            .yy.          /yyy`          oy+  .yy-        oy+  :yy                                         .yyyyyyy+        /ys         oyyyyyy.        syy/  yy.        :yyyyyy/                       
            -MM:          mMMM:          dMh .dMo         mMy  +MM                                         .oodMNoo/        sMN         dMmoooo`        mMMm``MM-        +MMsooo:                       
            -MM:         .MmyMy          dMh`dMo          mMy  +MM                                            sMN           sMN         dMh             mMNM+`MM-        +MM`                           
            -MM:         oMy/MN`         dMdhMd           mMy  +MM                                            sMN           sMN         dMd///`         mMoNm`MM-        +MM///-                        
            -MM:         dM/`MM:         dMMMMM:          mMy  +MM                                            sMN           sMN         dMNddd:         mM+oMoMM-        +MMddds                        
            -MM:        .MM-.dMy         dMN/dMd          mMy  +MM                                            sMN           sMN         dMh```          mM+`NNMM-        +MM.```                        
            -MM:        +MMmmNMN`        dMh -MM+         mMy  +MM                                            sMN           sMN         dMh             mM+ +MMM-        +MM`                           
          :odMm`        dMo..:MM:        dMh  sMN.        oMNo+mMy                                            sMN           sMN         dMmoooo`        mM+ `mMM-        +MMsooo:                       
          /ys+.        `yy.   sy/        oy+  `yy:         /shhy+`                                            /ys           /ys         oyyyyyy.        sy:  /yy.        :yyyyyy/                       
                                                                                                                                                                                                        
                                                                                                                                                                                                        
                                                                                                                                                                                                        
                                                                                                                                                                                                        
                                                                                                                                                                                                        
           ++-                  +++:                                 ++++/:`         :++          `++-          -+++`                                :++++/:`             +++++++`                      
           NMs                 .MMMm                                `MMmydMm.        sMm          `MM+          yMMM/                                sMMhhmMd`            NMmyyyy`                      
           NMs                 +MyNM-                               `MMo `NMo        sMm          `MM+         `NMyMh                                sMN  /MM.            NMs                           
           NMs                 dM:hMs                               `MM+ `NMo        sMm          `MM+         :Md-MM`                               sMN..+MN`            NMy---                        
           NMs                .MN`+Mm                               `MMmhdMd.        sMm          `MM+         yMo`NM/                               sMMdmMN/             NMNddd.                       
           NMs                +Md`:MM-                              `MMy//:`         sMm          `MM+        `NM:`hMh                               sMN--sMN.            NMy...                        
           NMs                dMNddMMo                              `MM+             sMm          .MM+        :MMddmMN`                              sMN  -MM:            NMs                           
           NMh///:           .MM/--yMm                              `MM+             sMm        ./sMM:        sMh--:MM/                              sMN  -MM:            NMh///:                       
           ddddddh           :dh   :dd.                              dd/             odh        /dhy:         hd/   ydo                              +dh  .dd:            hdddddd`                      
                                                                                                                                                                                                        
                                                                                                                                                                                                        
                                                                                                                                                                                                        
                                                                                                                                                                                                        
                                                                                                                                                                                                        
            .://-`                        .::::-.                           :::.                         .::-  .:.                       `::::-.                         -::::::`                       
           sNNdmMd.                       sMMmmNNy                         .MMMd                         oMMN. yMy                       /MMmmNNh`                       yMMmmmm:                       
          .MM+  mMs                       sMN` /MM.                        oMhMM.                        oMMMy yMy                       /MM- -MM+                       yMm                            
          -MM:  :/-                       sMN``/MM.                        dM:mM+                        oMddM.yMy                       /MM.  NMo                       yMm```                         
          -MM:`yyy+                       sMMddNN+                        .MN`sMh                        oMd:MyyMy                       /MM.  NMo                       yMMddd/                        
          -MM: +mMy                       sMN//hMm`                       +Mh :MM`                       oMd dMmMy                       /MM.  NMo                       yMm---`                        
          -MM:  dMy                       sMN  -MM:                       dMmhhMM+                       oMd :MMMy                       /MM. `NMo                       yMm                            
          `NMo`.mMo                       sMN  -MM:                      .MM+//dMh                       oMd  hMMy                       /MM:./MM/                       yMm....`                       
           /dNNNNs`                       oNm  .NN/                      /Nd   +NN`                      +Nh  :NNs                       :NNNNNd+                        yNNNNNN:                       
             `.`                           ``   ``                        ``    ``                        ``   ``                         ````                            ``````      
			 
⣠⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠛⢉⢉⠉⠉⠻⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⠟⠠⡰⣕⣗⣷⣧⣀⣅⠘⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⠃⣠⣳⣟⣿⣿⣷⣿⡿⣜⠄⣿⣿⣿⣿⣿
⣿⣿⣿⣿⡿⠁⠄⣳⢷⣿⣿⣿⣿⡿⣝⠖⠄⣿⣿⣿⣿⣿
⣿⣿⣿⣿⠃⠄⢢⡹⣿⢷⣯⢿⢷⡫⣗⠍⢰⣿⣿⣿⣿⣿
⣿⣿⣿⡏⢀⢄⠤⣁⠋⠿⣗⣟⡯⡏⢎⠁⢸⣿⣿⣿⣿⣿
⣿⣿⣿⠄⢔⢕⣯⣿⣿⡲⡤⡄⡤⠄⡀⢠⣿⣿⣿⣿⣿⣿
⣿⣿⠇⠠⡳⣯⣿⣿⣾⢵⣫⢎⢎⠆⢀⣿⣿⣿⣿⣿⣿⣿
⣿⣿⠄⢨⣫⣿⣿⡿⣿⣻⢎⡗⡕⡅⢸⣿⣿⣿⣿⣿⣿⣿
⣿⣿⠄⢜⢾⣾⣿⣿⣟⣗⢯⡪⡳⡀⢸⣿⣿⣿⣿⣿⣿⣿
⣿⣿⠄⢸⢽⣿⣷⣿⣻⡮⡧⡳⡱⡁⢸⣿⣿⣿⣿⣿⣿⣿
⣿⣿⡄⢨⣻⣽⣿⣟⣿⣞⣗⡽⡸⡐⢸⣿⣿⣿⣿⣿⣿⣿
⣿⣿⡇⢀⢗⣿⣿⣿⣿⡿⣞⡵⡣⣊⢸⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⡀⡣⣗⣿⣿⣿⣿⣯⡯⡺⣼⠎⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣧⠐⡵⣻⣟⣯⣿⣷⣟⣝⢞⡿⢹⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⡆⢘⡺⣽⢿⣻⣿⣗⡷⣹⢩⢃⢿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣷⠄⠪⣯⣟⣿⢯⣿⣻⣜⢎⢆⠜⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⡆⠄⢣⣻⣽⣿⣿⣟⣾⡮⡺⡸⠸⣿⣿⣿⣿
⣿⣿⡿⠛⠉⠁⠄⢕⡳⣽⡾⣿⢽⣯⡿⣮⢚⣅⠹⣿⣿⣿
⡿⠋⠄⠄⠄⠄⢀⠒⠝⣞⢿⡿⣿⣽⢿⡽⣧⣳⡅⠌⠻⣿
⠁⠄⠄⠄⠄⠄⠐⡐⠱⡱⣻⡻⣝⣮⣟⣿⣻⣟⣻
*/
int sus_user,sus_pass;

int login(userlen loguser, userlen logpass,FILE*arch_admin)
{
    auth reg;
    rewind(arch_admin);
    //fseek (arch_admin,0*sizeof(userlen),SEEK_SET);
	fread(&reg ,sizeof(auth),1,arch_admin);
	printf("\nINICIADO");
	while(!feof(arch_admin))//
	{
		printf("\n\nstrcmp(%s,%s)",loguser,reg.user);
		if(strcmp(loguser,reg.user)==0)
	    {
	        sus_user=1;
            if(strcmp(logpass,reg.password)==0)
            {
                printf("\n\nstrcmp(%s,%s)",logpass,reg.password);
				sus_pass=1;
            }
            else
            {
                sus_pass=0;
            }
	    }
	    else
	    {
		    sus_user=0;
	    }

		if(sus_user==1 && sus_pass==1)
    	{
         	return 1;
    	}

		fread(&reg ,sizeof(auth),1,arch_admin);
	}
	return 0;
}

int searchmodule(userlen suser, userlen spass,FILE*arch_admin)
{
	auth reg;
	fread(&reg.user ,sizeof(userlen),1,arch_admin);
	while(!feof(arch_admin))
	{
		if(strcmp(reg.user,suser)==0)
		{
			return reg.mod;
		}
		fread(&reg.user ,sizeof(userlen),1,arch_admin);
	}
}
