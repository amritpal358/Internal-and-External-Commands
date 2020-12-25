#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdio.h>
int main(){
	int i=0,po=0;
	int kl=0,lp=0;
	char mat[1000][1000],stor_his[1000][1000];
	char cwd[1000],comm[1000];
	while(1){
		getcwd(cwd,sizeof(cwd));
		printf("%s  =====>",cwd);
		scanf("%[^\n]%*c",comm);
		i=0;
		char* vAl = strtok(comm," ");
		int len=strlen(comm);
		if(len>0){
			//printf("%d",po);
			//if(po>1){
			//	print("%s","hello");
			//}
			strcpy(stor_his[po],comm);
			//printf("%d",po);
			po++;
		}
		while (vAl != 0){
			strcpy(mat[i],vAl);
			//if(vAl>0){
			//	printf("%c",mat[i]);
			//}
			vAl = strtok(0," ");
			//printf("%c",vAl);
			i+=1;
		}
		strcpy(mat[i],"NULL");
// if  user put command cd------------------------------------------------ 
		if(strcmp(mat[0],"cd")==0){
                        chdir(mat[1]);
			//if(chdir(mat[1]==-1){
			//}
			//else{
			//}
                        getcwd(cwd,sizeof(cwd));
                        //printf("%d",chdir(mat[1]));
			printf("working direct:   %s \n",cwd);
			kl+=1;
                }
// if user put command history---------------------------------------------
		else if(strcmp(mat[0],"history")==0){
			kl+=1;
			for(int it=0;it<po;it++){
				//if(x==0){
				//	x=x+1;
				//	}
				printf("%s \n",stor_his[it]);
				kl+=1;
			}
		}
//if user put command exit--------------------------------------------------
                else if(strcmp(mat[0],"exit")==0){
			//printf("%c",mat[0]);
			//if(len(mat[0])!=0){
			//	}
                        exit(0);
			kl+=1;
                        return 0;
                }
//if user put the pwd-------------------------------------------------- 
		else if(strcmp(mat[0],"pwd")==0){
			getcwd(cwd,sizeof(cwd));
			//int len =sizeof(cwd);
			//if(len!=0){
			//printf("hklo");
			//}
			kl+=1;
			printf("woorking direct: %s \n",cwd);
		}
//if user put command echo----------------------------------------------------
		else if(strcmp(mat[0],"echo")==0){
			//if user put command ech -n
			if(strcmp(mat[1],"-n")==0){
				//if(len!=0){
                        //		printf("hklo");
                        //	}
				for(int i1=2; i1<i; i1++){
					kl+=1;

					if(strcmp(mat[i1],"\"")==0){
						//if(len!=0){
                        //			printf("hklo");
                        //			}

						continue;
					}
					for(int y=0; y<strlen(mat[i1]);y++){
						//if(len!=0){
                        //				printf("hklo");
                        //			}

						if(mat[i1][y]==34){
							//if(len!=0){
                        //					printf("hklo");
                        //				}

							continue;
						}
						printf("%c",mat[i1][y]);
					}
				
				}
			}
			else{
				for(int i1=1; i1<i; i1++){
					kl+=1;
					//if(len!=0){
                        //printf("hklo");
                        //}

					if(strcmp(mat[i1],"\"")==0){
						//if(len!=0){
                        //				printf("hklo");
                        //				}

						continue;
						kl+=1;
					}
					for(int y=0; y<strlen(mat[i1]); y++){
						if(mat[i1][y]==34){
							continue;
							kl+=1;
						}
						printf("%c",mat[i1][y]);
					}
				}
				printf("\n");
			}
		}
//if user put command ls-----------------------------------------------------
		else if(strcmp(mat[0],"ls")==0){
			char gh[1000];
			gh[0]='-';
			int p=1;
			kl=1;
			for(int i=1;i<15;i++){
				if(strcmp(mat[i],"NULL")==0){
					kl+=1;
					break;
				}
				for(int j=0;j<strlen(mat[i]);j++){
					if(mat[i][j]!='-'){
						kl+=2;
						gh[p]=mat[i][j];
						kl=2;
						p+=1;
					}
				}
			}
			//if(strcmp(mat[1],gh)==0){
			//	printf("%s","its an -");
			//}
			strcpy(mat[1],gh);
			char *argv[4];
			/*if(strcmp(mat[1],gh)==0){
                                printf("%s","its an -");
                        }*/
			if(strcmp(mat[2],"NULL")==0){
				argv[0]=mat[0];
				argv[1]=mat[1];
				//if(strcmp(mat[1],gh)==0){
                        //      printf("%s","its an -");
                        //}
				argv[2]=NULL;
				argv[3]=NULL;
			}
			else{
				argv[0]=mat[0];
				argv[1]=mat[1];
				//if(strcmp(mat[1],gh)==0){
                        //      printf("%s","its an -");
                        //}
				argv[2]=mat[2];
				argv[3]=NULL;
			}
			if(strcmp(mat[1],"NULL")==0 || strcmp(mat[1],"-")==0){
				argv[1]=NULL;
			}
			int pid = fork();
			//if(strcmp(mat[1],gh)==0){
                        //      printf("%s","its an -");
                        //}
			if(pid==0){
				execvp(argv[0],argv);
				/*if(*buffers!=','){
                        strcat(namePtrs,buffers);
                }
                if(*buffers=='\n'){
                        if(counts>=201){
                                sums+=atoi(namePtrs)
                        }
                        *namePtrs=0;
                        sums=0;
                        counts++;
                        ks=0;
                        printf("\n");
                }*/
			}
			else{
				wait(0);
			}
			memset(gh, 0, sizeof gh);
		}
//if user put cat-------------------------------------------------------------
		else if(strcmp(mat[0],"cat")==0){
			char *argv[4];
			if(strcmp(mat[2],"NULL")==0){
				argv[0]=mat[0];
				argv[1]=mat[1];
				argv[2]=NULL;
				argv[3]=NULL;
			}
			else{
				argv[0]=mat[0];
				kl=1;
				argv[1]=mat[1];
				kl+=1;
				argv[2]=mat[2];
				kl+=1;
				argv[3]=NULL;
				kl+=1;
			}
			if(strcmp(mat[1],"NULL")==0 || strcmp(mat[1],"-")==0){
			       	argv[1]=NULL;
				kl=1;
			}
			int pid = fork();
			if(pid==0){
				kl+=1;
			       	execvp(argv[0],argv);
				/*if(*buffers!=','){
                        strcat(namePtrs,buffers);
                }
                if(*buffers=='\n'){
                        if(counts>=201){
                                sums+=atoi(namePtrs)
                        }
                        *namePtrs=0;
                        sums=0;
                        counts++;
                        ks=0;
                        printf("\n");
                }*/

			}
			else{
				wait(0);
			}
		}
//--------------------------------------------------------------------------
		else{
			char *argv[4];
			if(strcmp(mat[2],"NULL")==0){
				lp=1;
				argv[0]=mat[0];
				lp+=1;
                		argv[1]=mat[1];
				lp+=1;
                		argv[2]=NULL;
				lp+=1;
                		argv[3]=NULL;
				lp+=1;
			}
			else{
				lp=1;
				argv[0]=mat[0];
				lp+=1;
				argv[1]=mat[1];
				lp+=1;
                		argv[2]=mat[2];
				lp+=1;
                		argv[3]=NULL;
			}
			if(strcmp(mat[1],"NULL")==0 || strcmp(mat[1],"-")==0){
				argv[1]=NULL;
				lp=1;
			}
			int pid = fork();
			if(pid==0){
				execvp(argv[0],argv);
				/*if(*buffers!=','){
                        strcat(namePtrs,buffers);
                }
                if(*buffers=='\n'){
                        if(counts>=201){
                                sums+=atoi(namePtrs)
                        }
                        *namePtrs=0;
                        sums=0;
                        counts++;
                        ks=0;
                        printf("\n");
                }*/

			}
			else{
				wait(0);
			}
		}int hjip=0;
		memset(mat, hjip, sizeof(mat));
	}
	return 0;
}
