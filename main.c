#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "animal.h"
#include "sessoes.h"
#include <assert.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ",");
            tok && *tok;
            tok = strtok(NULL, ",\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

int get_size(const char* file_name)
{
    FILE *file = fopen(file_name, "r");

    if(file == NULL)
        return 0;

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fclose(file);

    return size;
}

int main(void) {
	
		int i=1; 
					      
   	
   int escolha=1; 
   int id;         
   char*nome=malloc(255);    
   char*especie=malloc(255); 
   char*raca=malloc(255); 
   int idade; 
   char*nomeproprietario=malloc(255); 
   float conta; 
   char*telefone=malloc(11); 
   
   //sessoes
        int idsession; 
        char*data=malloc(255); 
		char*tipo=malloc(255); 
		char*sintomas=malloc(255); 
		char*diagnostico=malloc(255); 
		char*vacina=malloc(255); 
		char*exame=malloc(255); 
		float preco;
	
	
	   printf("...LIMPANDO BASE DE DADOS ANTERIOR..."); 
	 	if (remove("petnames.txt") == 0) 
	 			printf("...ARQUIVO EXCLUIDO COM SUCESSO..."); 
	 		else
				printf("...NAO FOI POSSIVEL EXCLUIR ARQUIVO."); 
		

       criar_lista(0,"COSTELINHA","CACHORRO","DESCONHECIDO",1,"DOUG FUNNY",100,0);
       create_list(0,0, "00/00", 1, "N","N", "N", "N", 0); 
   
   //fp = fopen("newfile.txt", "w+");

   
	//nome = malloc(sizeof(nome)); 
	//especie = malloc(sizeof(especie)); 
	//raca = malloc(sizeof(raca)); 
	//nomeproprietario = malloc(sizeof(nomeproprietario)); 
	//telefone = malloc(sizeof(telefone)); 
	    int contagem=1;     	        		
		while(escolha!=8){
		    		   		
			//printf("Tamanho da lista: %d\n\n", tamanho_lista());
			printf(" \n %8s \n","XXXXXXXXXXXXXXXXX  CONSULTORI VET DR LEGAL XXXXXXXXXXXXXXXXXXXXXXXXX"  );  
		    printf("%8d\t%8s\n", 1,"CADASTRAR ANIMAL");		
		    printf("%8d\t%8s\n", 2,"REMOVER ANIMAL");		
		    printf("%8d\t%8s\n", 3,"ALTERAR DADOS DO ANIMAL");
		    printf("%8d\t%8s\n", 4,"INFORMACAO DO ANIMAL");
		    printf("%8d\t%8s\n", 5,"GERAR RELATORIO");
		    printf("%8d\t%8s\n", 6,"LISTAR ANIMAIS");
		    printf("%8d\t%8s\n", 7,"REALIZAR SESSAO");
		    printf("%8d\t%8s\n", 8,"ENCERRAR");
		    		  
            char buff[100]; 
            memset(buff,0,sizeof(buff)); 		    												
	        printf("Escolha uma opcao: ");
	    	scanf("%d",&escolha);
            fflush(stdin); 

				
		// estrutura switch
		switch (escolha) {
		
				case 1:
				{					    
									    	
				
					printf("\n\n Opcao escolhida: 1 \n ");	
					printf("INSIRA O NOME DO ANIMAL:");						
					fgets(nome,255,stdin); 
					nome[strlen(nome) - 1] = '\0';

					fflush(stdin); 
					printf("INSIRA A ESPECIE DO ANIMAL:");		
					fgets(especie,255,stdin); 
					especie[strlen(especie) - 1] = '\0';

					fflush(stdin);
					printf("INSIRA A RACA DO ANIMAL:");		
					fgets(raca,255,stdin); 
					raca[strlen(raca) - 1] = '\0';

					fflush(stdin);
					printf("INSIRA A IDADE DO ANIMAL:");						
					scanf("%d",&idade); 					
					fflush(stdin);
					printf("INSIRA O NOME DO PROPRIETARIO DO ANIMAL:");		
					fgets(nomeproprietario,255,stdin); 
					nomeproprietario[strlen(nomeproprietario) - 1] = '\0';

					fflush(stdin);
					printf("INSIRA O VALOR DA CONTA:");						
					scanf("%f",&conta); 
					fflush(stdin);
					printf("INSIRA O VALOR DO TELEFONE:");		
					fgets(telefone, 255, stdin); 
					telefone[strlen(telefone) - 1] = '\0';

					fflush(stdin);
					//int l = tamanho_lista(); 
					adicionar_lista(contagem,nome,especie, raca, idade, nomeproprietario, conta, telefone ); 
					contagem++; 										
					
					printf("SALVANDO INFORMACOES..."); 
					    					    					    
				     	FILE * fptr;
					    fptr = fopen("petnames.txt", "w");
					
					    if(fptr==NULL)
					    {
					        printf("Error\n");
					    }
					
					    else
					    {
					    	t_animal *aux = cabeca;
					    	int t = 1; 
					        while(aux != NULL)
					        {
					            //fprintf(fptr, "\n %8s \n","XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n" );
					            fprintf(fptr,"%d,", t);
								fprintf(fptr,"%s,", aux->nomeAnimal);
								fprintf(fptr,"%s,", aux->especie);
								fprintf(fptr,"%s,", aux->raca);
								fprintf(fptr,"%d,", aux->idade);
								fprintf(fptr,"%s,", aux->nomeProprietario);
								fprintf(fptr,"%f,", aux->conta);
								fprintf(fptr,"%s,\n", aux->telefone);
								//fprintf(fptr,"\n %8s \n","XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"  ); 
					            aux = aux->prox;
					            t++; 
					        }
					    }
					
					    fclose(fptr);
					
        			break;								
				}
				
				case 2:
				{				
					printf("\n\n Opcao escolhida: 2 \n");
				
					int j, r; 
									
					printf("INSIRA O ID DO ANIMAL QUE DESEJA REMOVER:");						
				
					scanf("%d", &j); 															
						r=remover_elemento(j); 
						
						if(r==1){
						//FILE* stream = fopen("petnames.txt", "r");
						printf("LIMPANDO BASE DE DADOS ANTERIOR..."); 
					 	if (remove("petnames.txt") == 0) 
	      			 			printf("...ARQUIVO EXCLUIDO COM SUCESSO..."); 
	   				 		else
	      						printf("...NAO FOI POSSIVEL EXCLUIR ARQUIVO..."); 
						printf("... ELEMENTO REMOVIDO COM SUCESSO...");	
						//fclose(stream); 
												
						FILE* stream2= fopen("petnames.txt", "w");
							
							if(stream2==NULL)
					    {
					        printf("Error\n");
					    }
					
					    else
					    {
					    	t_animal *aux = cabeca;
					    	int t = 1; 
					        while(aux != NULL)
					        {
					            //fprintf(fptr, "\n %8s \n","XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n" );
					            fprintf(stream2,"%d,", t);
								fprintf(stream2,"%s,", aux->nomeAnimal);
								fprintf(stream2,"%s,", aux->especie);
								fprintf(stream2,"%s,", aux->raca);
								fprintf(stream2,"%d,", aux->idade);
								fprintf(stream2,"%s,", aux->nomeProprietario);
								fprintf(stream2,"%f,", aux->conta);
								fprintf(stream2,"%s,\n", aux->telefone);
								//fprintf(fptr,"\n %8s \n","XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"  ); 
					            aux = aux->prox;
					            t++; 
					        }
					    }
					
					    fclose(stream2);
							
						}else{
							
							printf("NAO FOI POSSIVEL REMOVER O ELEMENTO");						
					    }
					
																									
					break;
				}
				
				case 3:
				{	
				printf("\n\n Opcao escolhida: 3 \n");
					t_animal *ant = NULL;
					t_animal*p; 
			     	int j, r; 									
					printf("\n INSIRA O ID DO ANIMAL QUE DESEJA ALTERAR:");						
					scanf("%d", &j); 
					p = buscar_elemento(j,&ant); 
					if(p==NULL){
						
					printf("\n ANIMAL NAO ENCONTRADO"); 
					}else{
								
					fflush(stdin); 
																			
					printf("INSIRA O NOME DO ANIMAL:");						
					fgets(nome,30,stdin); 
					nome[strlen(nome) - 1] = '\0';

					fflush(stdin); 
					printf("INSIRA A ESPECIE DO ANIMAL:");		
					fgets(especie,30,stdin); 
					especie[strlen(especie) - 1] = '\0';

					fflush(stdin);
					printf("INSIRA A RACA DO ANIMAL:");		
					fgets(raca,30,stdin); 
					raca[strlen(raca) - 1] = '\0';

					fflush(stdin);
					printf("INSIRA A IDADE DO ANIMAL:");						
					scanf("%d",&idade); 					
										
					fflush(stdin);
					printf("INSIRA O VALOR DA CONTA:");						
					scanf("%f",&conta); 
					fflush(stdin);
					printf("INSIRA O VALOR DO TELEFONE:");		
					fgets(telefone, 11, stdin); 
					telefone[strlen(telefone) - 1] = '\0';

					fflush(stdin);
															
					p->nomeAnimal = nome; 
					p->especie = especie; 
					p->raca = raca; 
					p->idade = idade; 
					p-> telefone = telefone; 	
						
					//FILE* stream = fopen("petnames.txt", "r");
						printf("LIMPANDO BASE DE DADOS ANTERIOR..."); 
					 	if (remove("petnames.txt") == 0) 
	      			 			printf("...ARQUIVO EXCLUIDO COM SUCESSO..."); 
	   				 		else
	      						printf("...NAO FOI POSSIVEL EXCLUIR ARQUIVO..."); 
						//printf("REMOVIDO COM SUCESSO");	
					//	fclose(stream); 
												
						FILE* stream2= fopen("petnames.txt", "w");
							
							if(stream2==NULL)
					    {
					        printf("Error\n");
					    }
					
					    else
					    {
					    	t_animal *aux = cabeca;
					    	int t = 1; 
					        while(aux != NULL)
					        {
					            //fprintf(fptr, "\n %8s \n","XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n" );
					            fprintf(stream2,"%d,", t);
								fprintf(stream2,"%s,", aux->nomeAnimal);
								fprintf(stream2,"%s,", aux->especie);
								fprintf(stream2,"%s,", aux->raca);
								fprintf(stream2,"%d,", aux->idade);
								fprintf(stream2,"%s,", aux->nomeProprietario);
								fprintf(stream2,"%f,", aux->conta);
								fprintf(stream2,"%s,\n", aux->telefone);
								//fprintf(fptr,"\n %8s \n","XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"  ); 
					            aux = aux->prox;
					            t++; 
					        }
					    }
					
					    fclose(stream2);
												
					}
					
					break;
				}
				
				case 4:
				{				
					t_animal *ant = NULL;
					t_animal*p; 
					printf("\n\n Opcao escolhida: 4 \n");
					int j, r; 									
					printf("\n INSIRA O ID DO ANIMAL QUE DESEJA BUSCAR:");						
					scanf("%d", &j); 
					p = buscar_elemento(j,&ant); 
					if(p==NULL){
						
					printf("\n ANIMAL NAO ENCONTRADO"); 
					}else{
					printf("\n %8s \n","XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"  ); 
					printf("ID: %8d\n", p->v);
					printf("NOME: %8s\n", p->nomeAnimal);
					printf("ESPECIE: %8s\n", p->especie);
					printf("RACA: %8s\n", p->raca);
					printf("IDADE %8d\n", p->idade);
					printf("DONO: %8s\n", p->nomeProprietario);
					printf("CONTA: %8f\n", p->conta);
					printf("TELEFONE: %8s\n", p->telefone);
					printf("\n %8s \n","XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"  ); 	
						
					}
					
					
					
					break;
				
				}
				
				case 5:
				{									
					t_animal *ant;
					char str[255]; 
					char str2[255]; 
					char str3[255]; 
					int t; 
					strcpy(str3,"Animal_"); 					
					
					ant = malloc(sizeof(ant)); 
					ant = NULL; 
					//t_animal*p; 
					t_animal*no; 
					no=malloc(sizeof(no)); 
					t_sessoes*q=malloc(sizeof(t_sessoes)); 
					t_sessoes*auxiliar; 					
					//print_list(); 
					//t_sessoes *back = NULL;	
					float sum=0; 													
					
					printf("\n\n Opcao escolhida: 5 \n");
					int j, r, b, contador; 									
					printf("\n INSIRA O ID DO ANIMAL QUE DESEJA BUSCAR:");						
					scanf("%d", &j); 
					
					no = buscar_elemento(j, &ant); 
										
					
					if(no==NULL){
					//r = j; 	
					printf("\n ANIMAL NAO ENCONTRADO\n"); 
					}else{
						if(q==NULL){
							printf("\n SESSAO NAO ENCONTRADA\n"); 
							
						}else{
						
						
					      	FILE * fptr;														
							
							strcpy(str,no->nomeAnimal); 
							itoa(no->v,str2,255); 
							strcat(str3,str2); 														
							strcat(str3,str); 
					        fptr = fopen(strcat(str3,".txt"), "w");
					        //fptr = fopen("report.txt", "w");
					
						    if(fptr==NULL)
						    {
						        printf("Error\n");
						    }
						
						    else
						    {
	                                
	                            t = no->v;     	
                              // fprintf(fptr,"\n %8s \n","XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"  ); 																
					           fprintf(fptr, "\n %8s \n","XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n" );
					            fprintf(fptr,"ID DO ANIMAL: %d,", no->v);
								//fprintf(fptr,"%s,", no->nomeAnimal);
								fprintf(fptr,"ESPECIE: %s,", no->especie);
								fprintf(fptr,"RACA: %s,", no->raca);
								fprintf(fptr,"IDADE: %d,", no->idade);
								fprintf(fptr,"PROPRIETARIO: %s,", no->nomeProprietario);
								fprintf(fptr,"TOTAL: %f,", soma(t)+no->conta);
								fprintf(fptr,"TELEFONE: %s,\n", no->telefone);
								
								auxiliar=head; 									
								contador = 0; 																	 
																
								
							    while (auxiliar!=NULL && contador <11){
									
									if(auxiliar->v == t){
																					
										fprintf(fptr, "\n %8s \n","XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"  ); 										
										fprintf(fptr, "IDANIMAL: %8d\n", auxiliar->v);
										fprintf(fptr, "IDSESSAO: %8d\n", auxiliar->k);										
										fprintf(fptr,"DATA: %8s\n", auxiliar->data);
										fprintf(fptr, "TIPO: %8d\n", auxiliar->tipo);
										fprintf(fptr, "SINTOMAS: %8s\n", auxiliar->sintomas);
										fprintf(fptr, "DIAGNOSTICO %8s\n", auxiliar->diagnostico);
										fprintf(fptr, "VACINAS: %8s\n", auxiliar->vacinas);
										fprintf(fptr, "EXAMES: %8s\n", auxiliar->exames);
										fprintf(fptr, "PRECO: %8f\n", auxiliar->preco);
										fprintf(fptr, "\n %8s \n","XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"  ); 																						
									}
									
									
									auxiliar=auxiliar->prox; 
									
									contador++; 
									
							     }
							     
								 sum = soma(no->v)+no->conta; 
							     fprintf(fptr, "\n %8s \n","XXXXXXXXXXXXXXXXXXXXXXXXXXX SOMA TOTAL XXXXXXXXXXXXXXXXXXXXXXX\n"  );
								 fprintf(fptr, "\n %8f \n",sum);  										
							    
							 }
								//fprintf(fptr, "%s,\n",print_list()); 
								//fprintf(fptr,"\n %8s \n","XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"  ); 
					            printf("\n RELATORIO GERADO COM SUCESSO \n");                                 	                                													    						    						        					    					
					   		    fclose(fptr);
					   
					   }
						
						
					}
					
					    
						
					    
					break;
				
				}
				case 6:
				{			
				    fflush(stdout); 	
				    printf("ATUALIZANDO BASE DE DADOS..."); 					 
					
					if(get_size("petnames.txt") == 0)
					{
					    printf("BASE DE DADOS VAZIA OU INEXISTENTE.");
					    //id=0; 
					}
					else
					{
						
					FILE* stream = fopen("petnames.txt", "r");

				    char line[1024];
				    while (fgets(line, 1024, stream))
				    {
				        char* tmp = strdup(line);	
				        char* tmp2 = strdup(line);	
				        char* tmp3 = strdup(line);	
				        char* tmp4 = strdup(line);	
				        char* tmp5 = strdup(line);	
				        char* tmp6 = strdup(line);	
				        char* tmp7 = strdup(line);	
				        char* tmp8 = strdup(line);	
				        
						id = atoi(getfield(tmp, 1)); 						
						nome = getfield(tmp2, 2); 
						especie= getfield(tmp3, 3); 
						raca= getfield(tmp4, 4); 
						idade= atoi(getfield(tmp5, 5)); 
						nomeproprietario= getfield(tmp6, 6); 
						conta= strtof(getfield(tmp7, 7),NULL); 
						telefone= getfield(tmp8, 8); 
												
						
						fflush(stdin); 
						//printf(" %s\n", getfield(tmp, 5));
						//nome[30] = (char*)getfield(tmp2, 2);
						//printf("nome: %s", nome); 
				        //adicionar_lista(id,nome,especie,raca,idade,nomeproprietario,conta,telefone); 
				        printf("\n %8s \n","XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"  ); 
							printf("ID: %8d\n", id);
							printf("NOME: %8s\n", nome);
							printf("ESPECIE: %8s\n", especie);
							printf("RACA: %8s\n", raca);
							printf("IDADE %8d\n", idade);
							printf("DONO: %8s\n", nomeproprietario);
							printf("CONTA TOTAL: %8f\n", conta);
							printf("TELEFONE: %8s\n", telefone);
							printf("\n %8s \n","XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"  ); 
				        
				        
				        //printf("Field 3 would be %s\n", getfield(tmp, 5));
				        // NOTE strtok clobbers tmp
				        free(tmp);
				        fclose(stream); 
				        
						//printf("LIMPANDO BASE DE DADOS ANTERIOR..."); 
						//	if (remove("petnames.txt") == 0) 
		      			//			printf("ARQUIVO EXCLUIDO COM SUCESSO"); 
		   				//		else
		      			//			printf("NAO FOI POSSIVEL EXCLUIR ARQUIVO"); 
				        
				    }
					    
					}
				    
					printf("\n\n Opcao escolhida: 6");
					//system("cls");
					imprimir_lista(); 
					//print_list(); 
	                //system("Pause"); 
					break;
				
				}
				
				case 7:
				{			
				    int idanima,ls,tipo; 
				    float sum=0; 
				    //int idsession; 
			        //char*data=malloc(255); 
					//char*tipo=malloc(255); 
					//char*sintomas=malloc(255); 
					//char*diagnostico=malloc(255); 
					//char*vacina=malloc(255); 
					//char*exame=malloc(255); 
					//float preco;
				    ls = size_list(); 
				    
				    printf("\n\n Opcao escolhida: 7 \n ");	
					printf("INSIRA O ID DO ANIMAL:");						
					scanf("%d",&idanima); 										
					fflush(stdin); 
					printf("INSIRA A DATA:");		
					fgets(data,255,stdin); 
					data[strlen(data) - 1] = '\0';		
					fflush(stdin); 
					printf("INSIRA OS SINTOMAS:");		
					fgets(sintomas,255,stdin); 
					sintomas[strlen(sintomas) - 1] = '\0';
					fflush(stdin);
					printf("INSIRA O TIPO <1>VAC <2> CON <3> EXA:");		
					scanf("%d",&tipo); 	
					
					fflush(stdin); 
					printf("INSIRA A VACINA:");		
					fgets(vacina,255,stdin); 						
					vacina[strlen(vacina) - 1] = '\0';
					
					fflush(stdin); 
					printf("INSIRA OS EXAMES :");		
					fgets(exame,255,stdin); 						
					exame[strlen(exame) - 1] = '\0';
					fflush(stdin); 
					fflush(stdin); 
					printf("INSIRA O DIAGNOSTICO :");		
					fgets(diagnostico,255,stdin); 						
					diagnostico[strlen(diagnostico) - 1] = '\0';
					fflush(stdin); 			
					
					if(tipo ==1){												
						preco = 50; 
						
																		
					}else if(tipo==2){					   					   
					    preco = 30; 
					    
					}else if(tipo==3){					  					   
					   preco = 110; 					   
					   
					}else{
					   preco=0; 
					}
					
					
					add_list(idanima,ls, data, tipo, sintomas,diagnostico, vacina, exame, preco); 
										
					
					
					//sum = soma(); 
					
					//printf("SOMA TOTAL: %f", sum); 
															
					break;
				
				}
				
				//default:
				//{
				//system("cls"); 
				//main(); 
        		
        		
        	   //} 
        		
																		
			}
												 									
		}
		
		return 0;				
	}
	
	
	

