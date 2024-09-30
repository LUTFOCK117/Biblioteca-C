#include <stdio.h> 
#include <time.h> 
#include <windows.h>
#include <string.h>

int mult1(int y);
int mult2(int x);
int mult3(int j);
int mult4(int z, int e);

// Estas son las estructuras necesarias para el funcionamiento del programa //

// La primera estructura sirve para los registros de los clientes nuevos //
typedef struct
	{
		char  nom[40], correo[30], dir[40], tel[12];
		int  activado, id;
	}tnuevo;
	
// La segunda estructura funciona para los libros nuevos a registrar //
typedef struct 
	{
		char titulo[30], autor[40], editorial[30], tipo[1];
		int  anio, cantidad, activado2, id2;
		float precio;
	}tlibronuevo;
	
// La tercera estructura funciona para guardar las rentas de los libros, sirve para las consultas //
typedef struct
	{
		time_t tiempos;
		int us, lib, cant, estatus, dias, id3, dia1, mes1, anio1;
		char tiporl[1];
	}trentaleer;
	
//La cuarta lo que hace es colocar un contador de los libros que han sido vendidos a lo largo del periodo establecido en la biblioteca //	
typedef struct 
	{
		int cantlib, lib2, id4, dia2, mes2, anio2;
		float preclib, ivalib, totaliva;	
	}tventa;	
	
int main()
{
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd,SW_SHOWMAXIMIZED);
	int usuario,intentos = 0, contra, opcion, clientes, des=1, conf=0, aumento=0, libro, aumento2 = 0, des2=1, conf2 = 0,  cantidad=0, money,  aumento3 = 0, adeudo, id=0, id2=0, id3=0, id4=0,  biblioteca, dev, consulta, consulta2, elec;
	char conom[30], cread[40], tipo[1];
	
	time_t tiempo; // En esta parte, creo una variable para guardar el tiempo actual //
	time(&tiempo);
	
	time_t now; // De igual forma, esta la uso para guardar el tiempo en las variables de la estructura //
	struct tm*now_tm;
	now =time(NULL);
	now_tm = localtime(&now);
	
	FILE *crear; //Creo el primer archivo, el cual es de clientes //
	tnuevo nuevo;
	fpos_t *pos;
	
	crear = fopen("Clientes.dat", "ab");
	fclose(crear);
	
	FILE *crear2; //Creo un segundo archivos para libros //
	tlibronuevo libronuevo;
	
	crear2 = fopen("Libros.dat", "ab");
	fclose(crear2);
	
	FILE *crear3; //Creo un tercer archivo para rentar y leer los libros //
	trentaleer rentaleer;
	
	crear3 = fopen("Rentaleer.dat", "ab");
	fclose(crear3);
	
	FILE *crear4; // Creo un cuarto archivo, para vender los libros //
	tventa venta;
	
	crear4 = fopen("Venta.dat", "ab");
	fclose(crear4);
	
	
	// En esta primera seccion del programa, pedira el ID del Usuario o trabajador de la Biblioteca, siendo nuestras matriculas los usuarios y contraseñas //
	
	printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t\t\t\t\tBiblioteca.\n\n");
	printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");	
	printf("Usuario: ");
	scanf("%d", &usuario); // Usuario, se utiliza para poder ingresar la matricula de la cuenta de cada uno de los trabajadores //
	
	// En los While, si los usuarios son diferentes, lo volvera a pedir, si se equivoca mas de tres veces, se cierra la sesion y se termina el programa //
	
	while(usuario != 1907995 && usuario != 1941436 && usuario != 1897962 && usuario != 1842829)
	{
		system("cls");
		printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("\t\t\t\t\t\t\t\t\tBiblioteca.\n\n");
		printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");	
		printf("\aUsuario: ");
		scanf("%d", &usuario);  // Usuario, se utiliza para poder ingresar la matricula de la cuenta de cada uno de los trabajadores //
		intentos = intentos+1;
		if(intentos==2)
		{
			system("cls");
			printf("\t\t\t\t\t\t\aSE CIERRA SESION.");
			return 0;
		}
	}
	
	// Aqui, si en dado caso coloco un usuario correcto, pedira la contraseña del usuario, la cual como se habia comentado con anterioridad, es la misma matricula del usuario //
	
	system("cls");
	printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
	printf("\t\t\t\t\t\t\t\t\tBiblioteca.\n\n");
	printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");	
	printf("Usuario: %d", usuario);
	printf("\nContrase%ca: ", 164);
	scanf("%d", &contra); // Contra, se utiliza para poder colocar la contraseña de dicho inicio de sesion //
	intentos=0;
	
	// De igual forma, si se llega a equivocar 3 veces con la contraseña se cierra la sesion //
	
	while(contra != 1907995 && contra != 1941436 && contra != 1897962 && contra != 1842829)
	{
		system("cls");
		printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("\t\t\t\t\t\t\t\t\tBiblioteca.\n\n");
		printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");	
		printf("Usuario: %d", usuario);
		printf("\n\aContrase%ca: ",164);
		scanf("%d", &contra); // Contra, se utiliza para poder colocar la contraseña de dicho inicio de sesion //
		intentos = intentos+1;
		
		// Intentos, los intentos son los que se colocan para dependiendo de las veces en que te equivoques, entrar o salir del sistema por exceso de fallas //
		
		if(intentos==2)
		{
			system("cls");
			printf("\t\t\t\t\t\t\aSE CIERRA SESION.\n\n");
			return 0;
		}
	}
	
	intentos = 0; 
	
	do // Ciclo para seleccionar que quieres hacer y quien eres, dependiendo a tu respectiva matricula //
		{
	
			if(usuario==1897962)
				{
					system("cls");
					printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
					printf("Bienvenido Juan Manuel Martinez Ramirez.\t\t\t\t\t\t\t\t\t\t\t\t       %s", ctime(&tiempo));
					printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
					printf("\t\t\t\t\t\t\t\tBiblioteca FCFM.\n\n1)Clientes.\n2)Libros.\n3)Biblioteca.\n4)Consultas.\n5)Salir.\n\nIngresa tu opcion: ");
					scanf("%d", &opcion);	
				}


				if(usuario==1842829)
					{
						system("cls");
						printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
						printf("Bienvenido Ana Lizbeth Dominguez Garza.\t\t\t\t\t\t\t\t\t\t\t\t\t        %s", ctime(&tiempo));
						printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
						printf("\t\t\t\t\t\t\tBiblioteca FCFM.\n\n1)Clientes.\n2)Libros.\n3)Biblioteca.\n4)Consultas.\n5)Salir.\n\nIngresa tu opcion: ");
						scanf("%d", &opcion); 	// Opcion, es aquella que te da a elegir a que parte del programa quieres ir //
					}
			
				if(usuario==1941436)
					{
						system("cls");
						printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
						printf("Bienvenido Angel Ledezma Zavala.        \t\t\t\t\t\t\t\t\t\t\t\t\t%s", ctime(&tiempo));
						printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
						printf("\t\t\t\t\t\t\tBiblioteca FCFM.\n\n1)Clientes.\n2)Libros.\n3)Biblioteca.\n4)Consultas.\n5)Salir.\n\nIngresa tu opcion: ");
						scanf("%d", &opcion); 	// Opcion, es aquella que te da a elegir a que parte del programa quieres ir //
					}
			
				if(usuario==1907995)
			{
				system("cls");
				printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
				printf("Bienvenido Luis Armando Villanueva Garcia.\t\t\t\t\t\t\t\t\t\t\t\t%s", ctime(&tiempo));
				printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
				printf("\t\t\t\t\t\t\tBiblioteca FCFM.\n\n1)Clientes.\n2)Libros.\n3)Biblioteca.\n4)Consultas.\n5)Salir.\n\nIngresa tu opcion: ");
				scanf("%d", &opcion); 	// Opcion, es aquella que te da a elegir a que parte del programa quieres ir //
			}
			
			// En los cuatro usuarios, vienen establecidos las opciones, pueden ser 5 opciones, entrara en un switch y ejecutara su respectiva actividad, al seleccionar una, entrara a un submenu, si en dado caso se equivoca mas de 3 veces, se cierra sesion //
			
			switch(opcion)
			{
				case 1: 
				
						//En la seccion clientes comenzara a deslizar un menu con 3 opciones //
				
						system("cls");
						printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
						printf("\t\t\t\t\t\t\t\t\tClientes.\n\n");
						printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");	
						printf("1)Nuevo Cliente.\n2)Eliminar Cliente.\n3)Regresar al Menu Principal.\n\nIngresa tu opcion: ");
						scanf("%d", &clientes); // Clientes, dicha opcion te da a elegir que parte del programa quieres entrar //
						
						switch(clientes)
						{
							case 1: 
							
									// En esta parte, el alumno procedera a agregar los datos de cada cliente que se añada, estos vienen en la parte de arriba declarados en una estructura //
									system("cls");
									
									id=0;
									crear = fopen("Clientes.dat", "rb"); // NOTA: Se inicia un contador para poder saber en que va el id, y de esa forma, asignar un id irrepetible //
									fread(&nuevo, sizeof(tnuevo), 1, crear);
									while(!feof(crear))
									{
										fread(&nuevo, sizeof(tnuevo), 1, crear);
										id++;
									}
									fclose(crear);
									
									printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
									printf("\t\t\t\t\t\t\t\tNuevo Cliente.\n\n");
									printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");	
									
									crear = fopen("Clientes.dat", "ab"); // Se agregarn todos los datos en el archivo binario, es a de escritura tras terminar y b de binario //
									
									nuevo.id = id;
									printf("Su id es: %d\n", nuevo.id);
									printf("Escribe su nombre completo: ");
									fflush(stdin);
									gets(nuevo.nom);
									printf("Escribe su correo electronico: ");
									fflush(stdin);
									gets(nuevo.correo);
									printf("Escribe su telefono: ");
									fflush(stdin);
									gets(nuevo.tel);
									printf("Escribe su direccion: ");
									fflush(stdin);
									gets(nuevo.dir);
									nuevo.activado=1;
									fwrite(&nuevo, sizeof(tnuevo), 1, crear);
									fclose(crear); // Se escriben todos los datos con un simple write y se cierra el archivo //
									
									system("cls");
									printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
									printf("\t\t\t\t\t\t\tClientes Registrados.\n\n");
									printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
									
									// Imprimira a todos los usuarios con valor de 1 y 0 // 
									
									id = 0;
									crear = fopen("Clientes.dat", "rb");
									fread(&nuevo, sizeof(tnuevo), 1, crear);
									while(!feof(crear))
									{
											printf("ID: %d, NOMBRE: %s, CORREO: %s, TELEFONO: %s, DIRECCION: %s, ESTATUS: %d\n", nuevo.id, nuevo.nom, nuevo.correo, nuevo.tel, nuevo.dir, nuevo.activado);
											printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");	
											
										fread(&nuevo, sizeof(tnuevo), 1, crear);
										id++;
									}
									fclose(crear);			
										
									printf("\nAquel que tenga estatus igual a 1, esta activado, si tiene 0, es lo contrario.\nAGREGADO CON EXITO\nPresiona enter para continuar.");
									fflush(stdin);
									getchar();
							break;
					
							case 2: 
							
									// En esta parte se procedera a eliminar uno de los clientes que se encuentren en las listas, mostrandose los que ya no existen o los que existen todavia //
									
									system("cls");
									printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
									printf("\t\t\t\t\t\t\tClientes Registrados.\n\n");
									printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
									
									// Se mostraran a todos los clientes activados, la r es para leer y la b es de binario //
									
									id=0;									
									crear = fopen("Clientes.dat", "rb");
									fread(&nuevo, sizeof(tnuevo), 1, crear);
									while(!feof(crear))
									{
										if(nuevo.activado==1)
											{
												printf("ID: %d, NOMBRE: %s, CORREO: %s, TELEFONO: %s, DIRECCION: %s, ESTATUS: %d\n", nuevo.id, nuevo.nom, nuevo.correo, nuevo.tel, nuevo.dir, nuevo.activado);
												printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");	
											}
										fread(&nuevo, sizeof(tnuevo), 1, crear);
										id++;
									}
									fclose(crear);
									
									// Ingresa el usuario que quiera eliminarse, aumento es la variable que se usa para el id que se quiera eliminar //
							
									printf("\nIngresa el id que te gustaria borrar: "); // Elimina a los clientes que tengan el id comentado//
									scanf("%d", &aumento);
									
									id=0;
									crear = fopen("Clientes.dat", "rb");
									fread(&nuevo, sizeof(tnuevo), 1, crear);
									while(!feof(crear))
									{
											
										if(aumento==id)
										{
											if(nuevo.activado == 1) // Se lee y si su activacion es 1 entra a una confirmacion //
												{
													printf("\a\n\nConfirmar si lo quieres dar de baja.\n");
													printf("1)Seguir con la eliminacion.\n2)Ir a un submenu.\nIntroduce tu seleccion: ");
													scanf("%d", &conf);	
												}
												
											else if (nuevo.activado == 0) // Y si no, se manda a un submenu, para poder elegir otro cliente o volver al menu inicial //
												{
													conf = 2;
												}
										}
										fread(&nuevo, sizeof(tnuevo), 1, crear);
										id++;
									}
									fclose(crear);
									
									while(des == 1 && conf == 2) 
										{
											system("cls");
											printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
											printf("\t\t\t\t\t\t\tEliminacion de Clientes.\n\n");
											printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
										
											// Si en dado caso, el dato que ingreso para eliminar al cliente aun no existe o ya fue eliminado ingresara a este menu //
											
											printf("\aElige otro cliente o ingresa lo que te gustaria hacer.\n");
											printf("1)Seguir eligiendo.\n2)Regresar al menu principal.\nIntroduce tu seleccion: ");
											scanf("%d", &des);
											
											// Dependera de la desicion que tome el usuario es lo que hara el programa, saldra o entrara a volver a elegir otro cliente //
											
											switch(des)
												{
													case 1:
													
													system("cls");
													printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
													printf("\t\t\t\t\t\t\tClientes Registrados.\n\n");
													printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
														
														// Si desea seguir eligiendo volvera a repetir el proceso pasado en un bucle //
													
													id=0;	
													crear = fopen("Clientes.dat", "rb");
													fread(&nuevo, sizeof(tnuevo), 1, crear);
													while(!feof(crear))
														{
															if(nuevo.activado==1)
																{
																	printf("ID: %d, NOMBRE: %s, CORREO: %s, TELEFONO: %s, DIRECCION: %s, ESTATUS: %d\n", id, nuevo.nom, nuevo.correo, nuevo.tel, nuevo.dir, nuevo.activado);
																	printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");	
																}
															fread(&nuevo, sizeof(tnuevo), 1, crear);
															id++;
														}
													fclose(crear);
												
													printf("\nIngresa el id que te gustaria borrar: "); // Elimina a los clientes que tengan el id comentado//
													scanf("%d", &aumento);
													
													id=0;
													crear = fopen("Clientes.dat", "rb");
													fread(&nuevo, sizeof(tnuevo), 1, crear);
													while(!feof(crear))
													{
															
														if( aumento==id ){
															if(nuevo.activado == 1)
																{
																	printf("\a\n\nConfirmar si lo quieres dar de baja.\n");
																	printf("1)Seguir con la eliminacion.\n2)Ir a un submenu.\nIntroduce tu seleccion: ");
																	scanf("%d", &conf);	
																}
														}
														fread(&nuevo, sizeof(tnuevo), 1, crear);
														id++;
													}
													fclose(crear);
	
													break;	
												}
											
										}
										
										// Aqui aparecera una lista ya sin el cliente mencionado, siendo r+ modificacion y b binario //
									if(des == 1 && conf == 1)
										{
											system("cls");
											printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
											printf("\t\t\t\t\t\t\tClientes Registrados.\n\n");
											printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
											
											id = 0;
											crear = fopen("Clientes.dat", "r+b");
											fread(&nuevo, sizeof(tnuevo), 1, crear);
											while(!feof(crear))
												{
													if(aumento == nuevo.id)
														{
															nuevo.activado = 0;
															int pos = ftell(crear)-sizeof(tnuevo);
															fseek(crear, pos, SEEK_SET);
															fwrite(&nuevo,sizeof(tnuevo), 1, crear);
															break;
														}
													fread(&nuevo, sizeof(tnuevo), 1, crear);
													id++;
												}
											fclose(crear);
											
											id = 0;
											crear = fopen("Clientes.dat", "rb");
											fread(&nuevo, sizeof(tnuevo), 1, crear);
											while(!feof(crear))
											{
												if(nuevo.activado==1)
													{
														printf("ID: %d, NOMBRE: %s, CORREO: %s, TELEFONO: %s, DIRECCION: %s, ESTATUS: %d\n", id, nuevo.nom, nuevo.correo, nuevo.tel, nuevo.dir, nuevo.activado);
														printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");	
													}
												fread(&nuevo, sizeof(tnuevo), 1, crear);
												id++;
											}
											fclose(crear);

											printf("\nBORRADO CON EXITO\nPresiona enter para continuar.");
											fflush(stdin);
											getchar();
											des = 1;
											conf = 0;
										}
									
									// Si en dado caso no elimino a nadie, los valores seran estos y volveremos al principio del programa // 
									else if(des == 2 && conf == 2)
										{
											system("cls");
											conf = 0;
											des = 1;
										}		
							
							default :
							break;
							
						}
				break;
				
				case 2: 
				
						// De igual forma aqui aparecera un submenu donde deben de aparecer las opciones que se quieran realizar con los libros //
						
						system("cls");
						printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
						printf("\t\t\t\t\t\t\t\tLibros.\n\n");
						printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");	
						printf("1)Nuevo Libro.\n2)Editar Libro.\n3)Eliminar Libro.\n4)Regresar al Menu Principal.\n\nIngresa tu opcion: ");
						scanf("%d", &libro);
						
						// Eligira alguna y entrara a un switch //
						
						switch(libro)
							{
								case 1: system("cls");
								
									id2=0;
									crear2 = fopen("Libros.dat", "rb");
									fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
									while(!feof(crear2))
									{
										fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
										id2++;
									}
									fclose(crear2);
									
									// Ingresara los datos del libro nuevo en esta estructura //
									
									crear2 = fopen("Libros.dat", "ab");
									
									printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
									printf("\t\t\t\t\t\t\t\t\tNuevo Libro.\n\n");
									printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");			
									libronuevo.id2 = id2;
									printf("Su ISBN es: %d\n", libronuevo.id2);
									printf("Escribe el nombre del libro: ");
									fflush(stdin);
									gets(libronuevo.titulo);
									printf("Escribe el nombre del autor: ");
									fflush(stdin);
									gets(libronuevo.autor);
									printf("Escribe el tipo de libro que es, si es R de Renta o V de Venta: ");
									fflush(stdin);
									gets(libronuevo.tipo);
											
											// Aqui ocurre algo interesante, si ingresa una v o r minusculas, se transformaran en mayusculas en automatico para la operacion del programa //
											
									if(libronuevo.tipo[0] == 'v')
										{
											libronuevo.tipo[0] = 'V';
										}
											
									else if(libronuevo.tipo[0] == 'r')
										{
											libronuevo.tipo[0] = 'R';
										}
											
											// Entraran a un while, el cual mientras las letras que se ingresen sean diferentes de V o R, estara repitiendose hasta tener un dato de estos //
											
									while(libronuevo.tipo[0] !='V' && libronuevo.tipo[0] !='R')
										{
											system("cls");
											printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
											printf("\t\t\t\t\t\t\t\t\t\tNuevo Libro.\n\n");
											printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");			
											printf("Su ISBN es: %d\n", libronuevo.id2);
											printf("Escribe el nombre del libro: %s\n", libronuevo.titulo);
											printf("Escribe el nombre del autor: %s\n", libronuevo.autor);
											printf("Escribe el tipo de libro que es, si es R de Renta o V de Venta: \a");
											fflush(stdin);
											gets(libronuevo.tipo);
										}
											
											// De igual forma, ocurriran dos eventos diferentes a las letras que se tengan, si es V, pedira el valor del libro, y si es R, su valor sera 0 en automatico //

									if (libronuevo.tipo[0] == 'V') 
										{
											printf("Escribe el precio: ");
											fflush(stdin);
											scanf("%f", &libronuevo.precio);
										}
										
									else if (libronuevo.tipo[0] == 'R')
										{
											printf("Su precio es de 0.\n");
											libronuevo.precio = 0;
										}
										
									printf("Escribe el a%co de publicacion: ", 164);
									fflush(stdin);
									scanf("%d", &libronuevo.anio);
									printf("Escribe la cantidad que hay en stock: ");
									fflush(stdin);
									scanf("%d", &libronuevo.cantidad);
									printf("Escribe la editorial: ");
									fflush(stdin);
									gets(libronuevo.editorial);
									(libronuevo.activado2)=1;	
									
									fwrite(&libronuevo, sizeof(tlibronuevo), 1, crear2);
									fclose(crear2); // Se guardan y se cierra el archivo de crear 2 //
									
									system("cls");
									printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
									printf("\t\t\t\t\t\t\tLibros Registrados.\n\n");
									printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
									
									// Imprimira los libros que se tengan en memoria, desde los que estan activados, hasta los desactivados en este ciclo for //
									
									id2 = 0;
									crear2 = fopen("Libros.dat", "rb");
									fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
									while(!feof(crear2))
									{
											printf("ID: %d, TITULO: %s, AUTOR: %s, PRECIO: $%1.2f, F.P: %d, CANTIDAD: %d, EDITORIAL: %s, ESTATUS: %d, TIPO: %c\n", libronuevo.id2, libronuevo.titulo, libronuevo.autor,libronuevo.precio, libronuevo.anio, libronuevo.cantidad,  libronuevo.editorial,libronuevo.activado2, libronuevo.tipo[0]);
											printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
											
										fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
										id++;
									}
									fclose(crear2);
									
									printf("\nAGREGADO CON EXITO\nPresiona enter para continuar.");
									fflush(stdin);
									getchar();
							break;

							case 2: 
							
							system("cls");
							
							// Acá hara algo totalmente curioso, ya que imprimira todos los libros, para que se sepa cuales ya fueron eliminados y cuales no, para poder modificar algunos datos del libro //
							
							printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
							printf("\t\t\t\t\t\t\t\tModificacion de Libro.\n\n");
							printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
							
							
							id2 = 0;
							crear2 = fopen("Libros.dat", "rb");
							fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
							while(!feof(crear2))
								{
									if(libronuevo.activado2==1) //Imprira solamente los activados, ya que los desactivados no se pueden eliminar //
										{
											printf("ID: %d, TITULO: %s, AUTOR: %s, PRECIO: $%1.2f, F.P: %d, CANTIDAD: %d, EDITORIAL: %s, ESTATUS: %d, TIPO: %c\n", libronuevo.id2, libronuevo.titulo, libronuevo.autor,libronuevo.precio, libronuevo.anio, libronuevo.cantidad,  libronuevo.editorial,libronuevo.activado2, libronuevo.tipo[0]);
											printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
										}
									fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
									id2++;
								}
							fclose(crear2);
							
							printf("\nIngresa el ISBN que te gustaria modificar: ");
							scanf("%d", &aumento2); //Ingresas al libro que quieres modificar //
							
							id2 = 0;
							crear2 = fopen("Libros.dat", "rb");
							fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
							while(!feof(crear2))
								{
									if(aumento2 == libronuevo.id2)
										{
											if (libronuevo.activado2==1) //Al igual que el usuario, te da la eleccion de confirmar o ir a un submenu //
												{
													printf("\a\n\nConfirmar si lo modificar.\n");
													printf("1)Seguir con la modificacion.\n2)Ir a un submenu.\nIntroduce tu seleccion: ");
													scanf("%d", &conf2);			
												}
														
										else if (libronuevo.activado2==0) // Si ya no existe, en automatico, te manda al submenu //
												{
													conf2 = 2;
												}
										}
									fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
									id2++;
								}
							fclose(crear2);
							
							while(des2 == 1 && conf2 == 2)
									{
										system("cls");
											
										// Entrara al ciclo while, y decidira que hacer en cuanto al proyecto //
											
										printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
										printf("\t\t\t\t\t\t\t\tModificacion de Libros.\n\n");
										printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
										printf("\aEste libro ya no existe o aun no esta registrado, intentalo de nuevo.\n\n");
										printf("1)Seguir eligiendo.\n2)Regresar al menu principal.\nIntroduce tu seleccion: ");
										scanf("%d", &des2);
											
											// Si se desea la primera opcion entrara y seleccionara un nuevo libro //
										
										switch(des2)
											{
												case 1:	
													system("cls");	
													printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
													printf("\t\t\t\t\t\tLibros Registrados.\n\n");
													printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
													
													id2 = 0;
													crear2 = fopen("Libros.dat", "rb");
													fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
													while(!feof(crear2))
														{
															if(libronuevo.activado2==1)
																{
																	printf("ISBN: %d, TITULO: %s, AUTOR: %s, PRECIO: $%1.2f, F.P: %d, CANTIDAD: %d, EDITORIAL: %s, ESTATUS: %d, TIPO: %c\n", libronuevo.id2, libronuevo.titulo, libronuevo.autor,libronuevo.precio, libronuevo.anio, libronuevo.cantidad,  libronuevo.editorial,libronuevo.activado2, libronuevo.tipo[0]);
																	printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
																}
															fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
															id2++;
														}
													fclose(crear2);
													
													printf("\nIngresa el ISBN que te gustaria modificar: "); // Elimina a los libros que tengan el id comentado//
													scanf("%d", &aumento2);
													
													id2 = 0;
													crear2 = fopen("Libros.dat", "rb");
													fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
													while(!feof(crear2))
														{
															if(aumento2 == libronuevo.id2)
																{
																	if ((libronuevo.activado2)==1)
																		{
																			printf("\a\n\nConfirmar si lo quieres modificar.\n");
																			printf("1)Seguir con la modificar.\n2)Ir a un submenu.\nIntroduce tu seleccion: ");
																			scanf("%d", &conf2);			
																		}
																}
															fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
															id2++;
														}
													fclose(crear2);
													
													// Volvera a preguntar si quiere ser eliminado, o no //
												break;
											}
										}
										
								// Si el caso es positivo, se eliminaran los libros //
									if(des2 == 1 && conf2 == 1)
										{
											system("cls");		

											id2 = 0;
											crear2 = fopen("Libros.dat", "r+b"); // r+ es modificacion, de acuerdo al id seleccionado, y se reescribira el archivo //
											fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
											while(!feof(crear2))
												{
													if(aumento2 == libronuevo.id2)
														{
															printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
															printf("\t\t\t\t\t\t\t\tModificacion del Libro.\n\n");
															printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");	
															printf("ID: %d, TITULO: %s, AUTOR: %s, PRECIO: $%1.2f, F.P: %d, CANTIDAD: %d, EDITORIAL: %s, ESTATUS: %d, TIPO: %c\n", libronuevo.id2, libronuevo.titulo, libronuevo.autor,libronuevo.precio, libronuevo.anio, libronuevo.cantidad,  libronuevo.editorial,libronuevo.activado2, libronuevo.tipo[0]);
															printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
															
															printf("Escribe el tipo de libro que es, si es R de Renta o V de Venta: ");
															fflush(stdin);
															gets(libronuevo.tipo);
															
															if(libronuevo.tipo[0] == 'v')
																{
																	libronuevo.tipo[0] = 'V';
																}
																			
															else if(libronuevo.tipo[0] == 'r')
																{
																	libronuevo.tipo[0] = 'R';
																}
																			
															while(libronuevo.tipo[0] !='V' && libronuevo.tipo[0] !='R')
																{
																	system("cls");
																	printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
																	printf("\t\t\t\t\t\t\t\tModificacion.\n\n");
																	printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
																	printf("Escribe el tipo de libro que es, si es R de Renta o V de Venta: \a");
																	fflush(stdin);
																	gets(libronuevo.tipo);
																}
																			
								
															if (libronuevo.tipo[0] == 'V') //Determinar que valga 0 cuando es Renta y que valga algo si es venta TIENE FALLAS// 
																{
																	printf("Escribe el precio: ");
																	fflush(stdin);
																	scanf("%f", &libronuevo.precio);
																}
																		
															else if (libronuevo.tipo[0] == 'R')
																{
																	printf("Su precio es de 0.\n");
																	libronuevo.precio = 0;
																}
								
															printf("Escribe la cantidad que hay en stock: ");
															fflush(stdin);
															scanf("%d", &cantidad);
															
															libronuevo.cantidad = libronuevo.cantidad + cantidad;
												
															int pos = ftell(crear2)-sizeof(tlibronuevo);
															fseek(crear2, pos, SEEK_SET);
															fwrite(&libronuevo,sizeof(tlibronuevo), 1, crear2);
															break;
														}
													fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
													id2++;
												}
											fclose(crear2);
											system("cls");
											
											printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
											printf("\t\t\t\t\t\t\t\tModificacion del Libro.\n\n");
											printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");		
											
											id2 = 0;
											crear2 = fopen("Libros.dat", "rb");
											fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
											while(!feof(crear2))
												{
													if(libronuevo.activado2==1)
														{
															printf("ID: %d, TITULO: %s, AUTOR: %s, PRECIO: $%1.2f, F.P: %d, CANTIDAD: %d, EDITORIAL: %s, ESTATUS: %d, TIPO: %c\n", libronuevo.id2, libronuevo.titulo, libronuevo.autor,libronuevo.precio, libronuevo.anio, libronuevo.cantidad,  libronuevo.editorial,libronuevo.activado2, libronuevo.tipo[0]);
															printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
														}
													fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
													id2++;
												}
											fclose(crear2);
											
											printf("\nMODIFICADO CON EXITO CON EXITO\nPresiona enter para continuar.");
											fflush(stdin);
											getchar();
										}
									
										
									// Si no, volvera al menu principal //
									
									else if(des2 == 2 && conf2 == 2)
										{
											system("cls");
											des2 = 1;
										}

							break; 
							
							case 3: 
								system("cls");	
								
								// De forma parecida, pedira el id del libro, el cual sera seleccionado y se analizara si ya fue eliminado o aun no //
								
								printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
								printf("\t\t\t\t\t\t\t\tEliminar Libro.\n\n");
								printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
									
								id2 = 0;
								crear2 = fopen("Libros.dat", "rb");
								fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
								while(!feof(crear2))
									{
										if(libronuevo.activado2==1)
											{
												printf("ID: %d, TITULO: %s, AUTOR: %s, PRECIO: $%1.2f, F.P: %d, CANTIDAD: %d, EDITORIAL: %s, ESTATUS: %d, TIPO: %c\n", libronuevo.id2, libronuevo.titulo, libronuevo.autor,libronuevo.precio, libronuevo.anio, libronuevo.cantidad,  libronuevo.editorial,libronuevo.activado2, libronuevo.tipo[0]);
												printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
											}
										fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
										id2++;
									}
								fclose(crear2);
								
								printf("\nIngresa el ISBN que te gustaria eliminar: ");
								scanf("%d", &aumento2); //Seleccionar el ISBN //
								
								id2 = 0;
								crear2 = fopen("Libros.dat", "rb");
								fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
								while(!feof(crear2))
									{
										if(aumento2 == libronuevo.id2)
											{
												if (libronuevo.activado2==1) // Hace algo parecido a lo anterior //
													{
														printf("\a\n\nConfirmar si lo eliminar.\n");
														printf("1)Seguir con la eliminacion.\n2)Ir a un submenu.\nIntroduce tu seleccion: ");
														scanf("%d", &conf2);			
													}
															
											else if (libronuevo.activado2==0)
													{
														conf2 = 2;
													}
											}
										fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
										id2++;
									}
								fclose(crear2);
							
								while(des2 == 1 && conf2 == 2)
									{
										system("cls");
										
										// Entrara al ciclo while, y decidira que hacer en cuanto al proyecto //
										
										printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
										printf("\t\t\t\t\t\t\t\tEliminacion de Libros.\n\n");
										printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
										printf("\aEste libro ya no existe o aun no esta registrado, intentalo de nuevo.\n\n");
										printf("1)Seguir eligiendo.\n2)Regresar al menu principal.\nIntroduce tu seleccion: ");
										scanf("%d", &des2);
										
										// Si se desea la primera opcion entrara y seleccionara un nuevo libro //
									
									switch(des2)
										{
											case 1:	
												system("cls");	
												printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
												printf("\t\t\t\t\t\tLibros Registrados.\n\n");
												printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
												
												id2 = 0;
												crear2 = fopen("Libros.dat", "rb");
												fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
												while(!feof(crear2))
													{
														if(libronuevo.activado2==1)
															{
																printf("ID: %d, TITULO: %s, AUTOR: %s, PRECIO: $%1.2f, F.P: %d, CANTIDAD: %d, EDITORIAL: %s, ESTATUS: %d, TIPO: %c\n", libronuevo.id2, libronuevo.titulo, libronuevo.autor,libronuevo.precio, libronuevo.anio, libronuevo.cantidad,  libronuevo.editorial,libronuevo.activado2, libronuevo.tipo[0]);
																printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
															}
														fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
														id2++;
													}
												fclose(crear2);
												
												printf("\nIngresa el id que te gustaria borrar: "); // Elimina a los libros que tengan el id comentado//
												scanf("%d", &aumento2);
												
												id2 = 0;
												crear2 = fopen("Libros.dat", "rb");
												fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
												while(!feof(crear2))
													{
														if(aumento2 == libronuevo.id2)
															{
																if ((libronuevo.activado2)==1)
																	{
																		printf("\a\n\nConfirmar si lo quieres eliminar.\n");
																		printf("1)Seguir con la eliminacion.\n2)Ir a un submenu.\nIntroduce tu seleccion: ");
																		scanf("%d", &conf2);			
																	}
															}
														fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
														id2++;
													}
												fclose(crear2);
													
													// Volvera a preguntar si quiere ser eliminado, o no //
											break;
										}
									}
									
							// Si el caso es positivo, se eliminaran los libros //
								if(des2 == 1 && conf2 == 1)
									{	
										system("cls");		
										printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
										printf("\t\t\t\t\t\t\t\tLibros Registrados.\n\n");
										printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");	
										
										id2 = 0;
										crear2 = fopen("Libros.dat", "r+b"); // Los checa y los elimina //
										fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
										while(!feof(crear2))
											{
												if(aumento2 == libronuevo.id2)
													{
														libronuevo.activado2 = 0;
														int pos = ftell(crear2)-sizeof(tlibronuevo);
														fseek(crear2, pos, SEEK_SET);
														fwrite(&libronuevo,sizeof(tlibronuevo), 1, crear2);
														break;
													}
												fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
												id2++;
											}
										fclose(crear2);
										
										id2 = 0; // Imprime solamente los activados //
										crear2 = fopen("Libros.dat", "rb");
										fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
										while(!feof(crear2))
											{
												if(libronuevo.activado2==1)
													{
														printf("ID: %d, TITULO: %s, AUTOR: %s, PRECIO: $%1.2f, F.P: %d, CANTIDAD: %d, EDITORIAL: %s, ESTATUS: %d, TIPO: %c\n", libronuevo.id2, libronuevo.titulo, libronuevo.autor,libronuevo.precio, libronuevo.anio, libronuevo.cantidad,  libronuevo.editorial,libronuevo.activado2, libronuevo.tipo[0]);
														printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
													}
												fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
												id2++;
											}
										fclose(crear2);
										
											
										printf("\nBORRADO CON EXITO\nPresiona enter para continuar.");
										fflush(stdin);
										getchar();
									}
									
								// Si no, volvera al menu principal //
								
								else if(des2 == 2 && conf2 == 2)
									{
										system("cls");
										des2 = 1;
									}
											
							break;
								
							default :
							break;
						}
				break;
						
				case 3: system("cls");
						printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
						printf("\t\t\t\t\t\t\t\tBiblioteca.\n\n");
						printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");	
						printf("1)Comprar Libro.\n2)Rentar Libro.\n3)Prestamo en Sala.\n4)Regresar Libro.\n5)Regresar al Menu Principal\n\nIngresa tu opcion: ");
						scanf("%d", &biblioteca);
						
						switch(biblioteca)
							{
								case 1:
								system("cls");	
								printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
								printf("\t\t\t\t\t\t\t\t\t\tCompra.\n\n");
								printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
								printf("\t\t\t\t\t\t\t\t\tLibros En La Biblioteca.\n\n");
								printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
								
								id2 = 0;
								crear2 = fopen("Libros.dat", "rb");
								fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
								while(!feof(crear2))
									{
										if(libronuevo.activado2==1 && libronuevo.tipo[0] == 'V')
											{
												printf("ID: %d, TITULO: %s, AUTOR: %s, PRECIO: $%1.2f, F.P: %d, CANTIDAD: %d, EDITORIAL: %s, ESTATUS: %d, TIPO: %c\n", libronuevo.id2, libronuevo.titulo, libronuevo.autor,libronuevo.precio, libronuevo.anio, libronuevo.cantidad,  libronuevo.editorial,libronuevo.activado2, libronuevo.tipo[0]);
												printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
											}
										fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
										id2++;
									}
								fclose(crear2);
								
								printf("\nIngresa el ISBN que te gustaria comprar: "); 
								scanf("%d", &aumento2);
								
								id2 = 0;
								crear2 = fopen("Libros.dat", "rb");
								fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
								while(!feof(crear2))
									{
										if(aumento2 == libronuevo.id2)
											{
												if ((libronuevo.activado2)==1 && libronuevo.cantidad > 0 && libronuevo.tipo[0] == 'V')
													{
														printf("Cuantos te gustaria comprar: ");
														scanf("%d", &cantidad);
															
														libronuevo.cantidad = libronuevo.cantidad - cantidad;
															
														if(libronuevo.cantidad > 0 )
															{
																printf("\a\n\nConfirmar si lo quieres comprar.\n");
																printf("1)Seguir con la compra.\n2)Ir a un submenu.\nIntroduce tu seleccion: ");
																scanf("%d", &conf2);
															}		
													}
														
												if ((libronuevo.activado2)==0 || libronuevo.cantidad <= 0 || libronuevo.tipo[0] == 'R')
													{
														conf2 = 2;
													}
											}
										fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
										id2++;
									}
								fclose(crear2);
								
								while(des2 == 1 && conf2 == 2)
									{
										system("cls");
										printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
										printf("\t\t\t\t\t\t\t\tCompra de Libros.\n\n");
										printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
										printf("\aEste libro ya no existe, aun no esta registrado, solo esta para renta, o solo queda uno en stock, intentalo de nuevo.\n\n");
										printf("1)Seguir eligiendo.\n2)Regresar al menu principal.\nIntroduce tu seleccion: ");
										scanf("%d", &des2);
									
									switch(des2)
										{
											case 1:	
												system("cls");	
												printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
												printf("\t\t\t\t\t\t\t\tLibros En La Biblioteca.\n\n");
												printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
										
												id2 = 0;
												crear2 = fopen("Libros.dat", "rb");
												fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
												while(!feof(crear2))
													{
														if(libronuevo.activado2==1 && libronuevo.tipo[0] == 'V')
															{
																printf("ID: %d, TITULO: %s, AUTOR: %s, PRECIO: $%1.2f, F.P: %d, CANTIDAD: %d, EDITORIAL: %s, ESTATUS: %d, TIPO: %c\n", libronuevo.id2, libronuevo.titulo, libronuevo.autor,libronuevo.precio, libronuevo.anio, libronuevo.cantidad,  libronuevo.editorial,libronuevo.activado2, libronuevo.tipo[0]);
																printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
															}
														fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
														id2++;
													}
												fclose(crear2);
													
												printf("\nIngresa el ISBN que te gustaria comprar: "); // Resta a los libros que tengan el id comentado//
												scanf("%d", &aumento2);
												
												id2 = 0;
												crear2 = fopen("Libros.dat", "rb");
												fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
												while(!feof(crear2))
													{
														if(aumento2 == libronuevo.id2)
															{
																if ((libronuevo.activado2)==1 && libronuevo.cantidad > 0 && libronuevo.tipo[0] == 'V')
																	{
																		printf("Cuantos te gustaria comprar: ");
																		scanf("%d", &cantidad);
																			
																		libronuevo.cantidad = libronuevo.cantidad - cantidad;
																			
																		if(libronuevo.cantidad > 0 )
																			{
																				printf("\a\n\nConfirmar si lo quieres comprar.\n");
																				printf("1)Seguir con la compra.\n2)Ir a un submenu.\nIntroduce tu seleccion: ");
																				scanf("%d", &conf2);
																			}		
																	}
															}
														fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
														id2++;
													}
												fclose(crear2);	
												
											break;
										}
									}
								
								if(des2 == 1 && conf2 == 1)
									{
										system("cls");
										
										id2 = 0;
										crear2 = fopen("Libros.dat", "r+b");
										fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
										while(!feof(crear2))
											{
												if(aumento2 == libronuevo.id2)
													{
														money = libronuevo.precio;
														libronuevo.cantidad = libronuevo.cantidad - cantidad;
														int pos = ftell(crear2)-sizeof(tlibronuevo);
														fseek(crear2, pos, SEEK_SET);
														fwrite(&libronuevo,sizeof(tlibronuevo), 1, crear2);
														break;
														
													}
												fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
												id2++;
											}
										fclose(crear2);	
										
										id4=0;
										crear4 = fopen("Venta.dat", "rb");
										fread(&venta, sizeof(tventa), 1, crear4);
										while(!feof(crear4))
										{
											fread(&venta, sizeof(tventa), 1, crear4);
											id4++;
										}
										fclose(crear4);
										
										crear4 = fopen("Venta.dat", "ab");
										
										venta.id4 = id4;
										venta.lib2 = aumento2; // La id del libro //
										venta.cantlib = cantidad;
										venta.dia2 = now_tm->tm_mday;;
										venta.mes2 = now_tm->tm_mon+1;
										venta.anio2 = now_tm->tm_year;
										venta.anio2 += 1900;
										venta.preclib = cantidad*(money);
										venta.ivalib = cantidad*(((money)/100)*16);
										venta.totaliva = cantidad*(money+(((money)/100)*16));
										
										fwrite(&venta, sizeof(tventa), 1, crear4);
										fclose(crear4);
									
										
										printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
										printf("\t\t\t\t\t\t\t\tBiblioteca Bisonte.\n\n");
										printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
										printf("\t\t\t\t\t\t\t\tCANTIDAD: %d\n", venta.cantlib);
										printf("\t\t\t\t\t\t\t\tPRECIO $%1.2f\n", venta.preclib);
										printf("\t\t\t\t\t\t\t\tIVA $%1.2f\n", venta.ivalib);
										printf("\t\t\t\t\t\t\t\tTOTAL: $%1.2f\n\n", venta.totaliva);
										printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
										
										printf("\nVENTA CON EXITO\nPresiona enter para continuar.");
										
										fflush(stdin);
										getchar();
										cantidad = 0;
										
									}
								
								else if(des2 == 2 && conf2 == 2)
									{
										system("cls");
										des2 = 1;
										cantidad = 0;
									}
									
								break;
								
								case 2:
									
									system("cls");
									printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
									printf("\t\t\t\t\t\t\t\t\tRenta.\n\n");
									printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
									printf("\t\t\t\t\t\t\tClientes Registrados.\n\n");
									printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
									
									id = 0;
									crear = fopen("Clientes.dat", "rb");
									fread(&nuevo, sizeof(tnuevo), 1, crear);
									while(!feof(crear))
									{
										if(nuevo.activado==1)
											{
												printf("ID: %d, NOMBRE: %s, CORREO: %s, TELEFONO: %s, DIRECCION: %s, ESTATUS: %d\n", nuevo.id, nuevo.nom, nuevo.correo, nuevo.tel, nuevo.dir, nuevo.activado);
												printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");	
											}
										fread(&nuevo, sizeof(tnuevo), 1, crear);
										id++;
									}
									fclose(crear);	
							
									printf("\nIngresa el id que te gustaria seleccionar: "); // Selecciona a los clientes que tengan el id comentado//
									scanf("%d", &aumento);
									
									conf = 0;
									
									id = 0;
									crear = fopen("Clientes.dat", "rb");
									fread(&nuevo, sizeof(tnuevo), 1, crear);
									while(!feof(crear))
									{
										if(aumento == nuevo.id)
											{
												if ((nuevo.activado)==1)
													{
														printf("\a\n\nConfirmar si lo quieres seleccionar.\n");
														printf("1)Seguir con la seleccion.\n2)Ir a un submenu.\nIntroduce tu seleccion: ");
														scanf("%d", &conf);			
													}
			
												// Se confirmara si se desea realizar la accion mencionada //
													
												if ((nuevo.activado)==0)
													{
														conf = 2;
													}
											}
										fread(&nuevo, sizeof(tnuevo), 1, crear);
										id++;
									}
									fclose(crear);

									// En caso negativo, se intreducira al while //
									
									while(des == 1 && conf == 2) 
										{
											system("cls");
											printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
											printf("\t\t\t\t\t\tSeleccion de Clientes.\n\n");
											printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
											printf("\aElige otro cliente o ingresa lo que te gustaria hacer.\n");
											printf("1)Seguir eligiendo.\n2)Regresar al menu principal.\nIntroduce tu seleccion: ");
											scanf("%d", &des);
											
											switch(des)
												{
													case 1:
													system("cls");
													printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
													printf("\t\t\t\t\t\tClientes Registrados.\n\n");
													printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
														
													id = 0;
													crear = fopen("Clientes.dat", "rb");
													fread(&nuevo, sizeof(tnuevo), 1, crear);
													while(!feof(crear))
														{
															if(nuevo.activado==1)
																{
																	printf("ID: %d, NOMBRE: %s, CORREO: %s, TELEFONO: %s, DIRECCION: %s, ESTATUS: %d\n", nuevo.id, nuevo.nom, nuevo.correo, nuevo.tel, nuevo.dir, nuevo.activado);
																	printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");	
																}
															fread(&nuevo, sizeof(tnuevo), 1, crear);
															id++;
														}
													fclose(crear);
												
													printf("\nIngresa el id que te gustaria seleccionar: "); // Selecciona al id del cliente que quiere la renta //
													scanf("%d", &aumento);
													
													id = 0;
													crear = fopen("Clientes.dat", "rb");
													fread(&nuevo, sizeof(tnuevo), 1, crear);
													while(!feof(crear))
														{
															if(aumento == nuevo.id)
																{
																	if ((nuevo.activado)==1)
																		{
																			printf("\a\n\nConfirmar si lo quieres seleccionar.\n");
																			printf("1)Seguir.\n2)Regresar al menu principal.\nIntroduce tu seleccion: ");
																			scanf("%d", &conf);	
																		}
																}
															fread(&nuevo, sizeof(tnuevo), 1, crear);
															id++;
														}
													fclose(crear);
													
													break;
													
													default:
													break;	
												}
										}
										
									if(des == 1 && conf == 1)
										{
											system("cls");	
											printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
											printf("\t\t\t\t\t\t\t\t\tRenta.\n\n");
											printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
											printf("\t\t\t\t\t\t\tSeleccionar Libro.\n\n");
											printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
											
											id2 = 0;
											crear2 = fopen("Libros.dat", "rb");
											fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
											while(!feof(crear2))
												{
													if(libronuevo.activado2==1 && libronuevo.tipo[0] == 'R')
														{
															printf("ID: %d, TITULO: %s, AUTOR: %s, PRECIO: $%1.2f, F.P: %d, CANTIDAD: %d, EDITORIAL: %s, ESTATUS: %d, TIPO: %c\n", libronuevo.id2, libronuevo.titulo, libronuevo.autor,libronuevo.precio, libronuevo.anio, libronuevo.cantidad,  libronuevo.editorial,libronuevo.activado2, libronuevo.tipo[0]);
															printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
														}
													fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
													id2++;
												}
											fclose(crear2);
									
											printf("\nIngresa el ISBN que te gustaria seleccionar: "); 
											scanf("%d", &aumento2);
											
											id2 = 0;
											crear2 = fopen("Libros.dat", "rb");
											fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
											while(!feof(crear2))
												{
													if(aumento2 == libronuevo.id2)
														{
															if ((libronuevo.activado2)==1 && libronuevo.tipo[0] == 'R' &&  libronuevo.cantidad > 0 )
																{
																	
																	printf("Cuantos te gustaria rentar: ");
																	scanf("%d", &cantidad);
																	libronuevo.cantidad = libronuevo.cantidad - cantidad;
																		
																	if(libronuevo.cantidad > 0 )
																		{
																			printf("\a\n\nConfirmar si lo quieres rentar.\n");
																			printf("1)Seguir.\n2)Regresar al menu principal.\nIntroduce tu seleccion: ");
																			scanf("%d", &conf2);
																		}
																				
																}
																
															else if ((libronuevo.activado2)==0 || libronuevo.tipo[0] == 'V' || libronuevo.cantidad <= 1)
																{
																	conf2 = 2;
																}
														}
													fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
													id2++;
												}
											fclose(crear2);
											
											while(des2 == 1 && conf2 == 2)
												{
													// Si en dado caso no cumple con algunas de las condiciones establecidas, se volvera a sumar la cantidad y comenzara el proceso //
													
													system("cls");
													printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
													printf("\t\t\t\t\t\tSeleccion de Libros.\n\n");
													printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
													printf("\aEste libro ya no existe o aun no esta registrado, intentalo de nuevo.\n\n");
													printf("1)Seguir eligiendo.\n2)Regresar al menu principal.\nIntroduce tu seleccion: ");
													scanf("%d", &des2);
											
											switch(des2)
												{
													case 1:	
														system("cls");	
														printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
														printf("\t\t\t\t\t\tLibros Registrados.\n\n");
														printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
															
														id2 = 0;
														crear2 = fopen("Libros.dat", "rb");
														fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
														while(!feof(crear2))
															{
																if(libronuevo.activado2==1 && libronuevo.tipo[0] == 'R')
																	{
																		printf("ID: %d, TITULO: %s, AUTOR: %s, PRECIO: $%1.2f, F.P: %d, CANTIDAD: %d, EDITORIAL: %s, ESTATUS: %d, TIPO: %c\n", libronuevo.id2, libronuevo.titulo, libronuevo.autor,libronuevo.precio, libronuevo.anio, libronuevo.cantidad,  libronuevo.editorial,libronuevo.activado2, libronuevo.tipo[0]);
																		printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
																	}
																fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
																id2++;
															}
														fclose(crear2);
															
														printf("\nIngresa el ISBN que te gustaria seleccionar: "); // Selecciona a los libros que tengan el ISBN marcado//
														scanf("%d", &aumento2);
														
														id2 = 0;
														crear2 = fopen("Libros.dat", "rb");
														fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
														while(!feof(crear2))
															{
																if(aumento2 == libronuevo.id2)
																	{
																		if ((libronuevo.activado2)==1 && libronuevo.tipo[0] == 'R' &&  libronuevo.cantidad > 0 )
																			{
																				
																				printf("Cuantos te gustaria rentar: ");
																				scanf("%d", &cantidad);
																				libronuevo.cantidad = libronuevo.cantidad - cantidad;
																					
																				if(libronuevo.cantidad > 0 )
																					{
																						printf("\a\n\nConfirmar si lo quieres rentar.\n");
																						printf("1)Seguir.\n2)Regresar a un submenu.\nIntroduce tu seleccion: ");
																						scanf("%d", &conf2);
																					}			
																			}
																	}
																fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
																id2++;
															}
														fclose(crear2);

													break;
													
													default:
													break; 
												}
											}
										}
										
									
									if(des2 == 1 && conf2 == 1 && des == 1 && conf == 1)
									{
										
										id2 = 0;
										crear2 = fopen("Libros.dat", "r+b");
										fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
										while(!feof(crear2))
											{
												if(aumento2 == libronuevo.id2)
													{
														libronuevo.cantidad = libronuevo.cantidad - cantidad;
														int pos = ftell(crear2)-sizeof(tlibronuevo);
														fseek(crear2, pos, SEEK_SET);
														fwrite(&libronuevo,sizeof(tlibronuevo), 1, crear2);
														break;
														
													}
												fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
												id2++;
											}
										fclose(crear2);	
										
										id3=0;
										crear3 = fopen("Rentaleer.dat", "rb");
										fread(&rentaleer, sizeof(trentaleer), 1, crear3);
										while(!feof(crear3))
										{
											fread(&rentaleer, sizeof(trentaleer), 1, crear3);
											id3++;
										}
										fclose(crear3);
		
										crear3 = fopen("Rentaleer.dat", "ab");
										rentaleer.id3 = id3;
										rentaleer.lib = aumento2;
										rentaleer.us = aumento;
										rentaleer.dias = 0;
										rentaleer.cant = cantidad;
										rentaleer.dia1 = now_tm->tm_mday;
										rentaleer.mes1 =  now_tm->tm_mon+1;
										rentaleer.anio1 = now_tm->tm_year;
										rentaleer.anio1 += 1900;
										rentaleer.tiporl[0] = 'R';
										rentaleer.estatus = 1;
										fwrite(&rentaleer, sizeof(trentaleer), 1, crear3);
										fclose(crear3);
												
									
										system("cls");
										printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
										printf("\t\t\t\t\t\tRenta.\n\n");
										printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
										
										id3=0;
										crear3 = fopen("Rentaleer.dat", "rb");
										fread(&rentaleer, sizeof(trentaleer), 1, crear3);
										while(!feof(crear3))
										{
											if(rentaleer.estatus == 1 && rentaleer.tiporl[0] == 'R')
											{
												printf("LUGAR: %d, ID: %d, ISBN: %d, CANTIDAD: %d, TIPO: %c, ESTATUS: %d, FECHA: %d/%d/%d \n", rentaleer.id3, rentaleer.us, rentaleer.lib, rentaleer.cant, rentaleer.tiporl[0], rentaleer.estatus,rentaleer.dia1, rentaleer.mes1, rentaleer.anio1);
												printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
											}
					
											fread(&rentaleer, sizeof(trentaleer), 1, crear3);
											id3++;
										}
										fclose(crear3);
											
										cantidad = 0;
										printf("\nAGREGADO CON EXITO\nPresiona enter para continuar.");
										fflush(stdin);
										getchar();
									}
									
									if(des == 2 && conf == 2)
										{
											system("cls");
											cantidad = 0;
											conf = 0;
											des = 1;
										}

									if(des2 == 2 && conf2 == 2)
										{
											system("cls");
											cantidad = 0;
											des2 = 1;
										}
									
								break;
								
								case 3:
									system("cls");
									printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
									printf("\t\t\t\t\t\t\t\t\tLeer en Sala.\n\n");
									printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
									printf("\t\t\t\t\t\t\tClientes Registrados.\n\n");
									printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
									
									id = 0;
									crear = fopen("Clientes.dat", "rb");
									fread(&nuevo, sizeof(tnuevo), 1, crear);
									while(!feof(crear))
									{
										if(nuevo.activado==1)
											{
												printf("ID: %d, NOMBRE: %s, CORREO: %s, TELEFONO: %s, DIRECCION: %s, ESTATUS: %d\n", nuevo.id, nuevo.nom, nuevo.correo, nuevo.tel, nuevo.dir, nuevo.activado);
												printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");	
											}
										fread(&nuevo, sizeof(tnuevo), 1, crear);
										id++;
									}
									fclose(crear);	
							
									printf("\nIngresa el id que te gustaria seleccionar: "); // Selecciona a los clientes que tengan el id comentado//
									scanf("%d", &aumento);
									
									conf = 0;
									
									// Se confirmara si se desea realizar la accion mencionada //
									
									
									id = 0;
									crear = fopen("Clientes.dat", "rb");
									fread(&nuevo, sizeof(tnuevo), 1, crear);
									while(!feof(crear))
									{
										if(aumento == nuevo.id)
											{
												if ((nuevo.activado)==1)
													{
														printf("\a\n\nConfirmar si lo quieres seleccionar.\n");
														printf("1)Seguir con la seleccion.\n2)Ir a un submenu.\nIntroduce tu seleccion: ");
														scanf("%d", &conf);			
													}
													
												else if ((nuevo.activado)==0)
													{
														conf = 2;
													}
											}
										fread(&nuevo, sizeof(tnuevo), 1, crear);
										id++;
									}
									fclose(crear);
									
									// En caso negativo, se intreducira al while //
									
									while(des == 1 && conf == 2) 
										{
											system("cls");
											printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
											printf("\t\t\t\t\t\tSeleccion de Clientes.\n\n");
											printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
											printf("\aElige otro cliente o ingresa lo que te gustaria hacer.\n");
											printf("1)Seguir eligiendo.\n2)Regresar al menu principal.\nIntroduce tu seleccion: ");
											scanf("%d", &des);
											
											switch(des)
												{
													case 1:
													system("cls");
													printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
													printf("\t\t\t\t\t\tClientes Registrados.\n\n");
													printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
														
													id = 0;
													crear = fopen("Clientes.dat", "rb");
													fread(&nuevo, sizeof(tnuevo), 1, crear);
													while(!feof(crear))
													{
														if(nuevo.activado==1)
															{
																printf("ID: %d, NOMBRE: %s, CORREO: %s, TELEFONO: %s, DIRECCION: %s, ESTATUS: %d\n", nuevo.id, nuevo.nom, nuevo.correo, nuevo.tel, nuevo.dir, nuevo.activado);
																printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");	
															}
														fread(&nuevo, sizeof(tnuevo), 1, crear);
														id++;
													}
													fclose(crear);	
											
													printf("\nIngresa el id que te gustaria seleccionar: "); // Selecciona a los clientes que tengan el id comentado//
													scanf("%d", &aumento);
													
													id = 0;
													crear = fopen("Clientes.dat", "rb");
													fread(&nuevo, sizeof(tnuevo), 1, crear);
													while(!feof(crear))
													{
														if(aumento == nuevo.id)
															{
																if ((nuevo.activado)==1)
																	{
																		printf("\a\n\nConfirmar si lo quieres seleccionar.\n");
																		printf("1)Seguir.\n2)Regresar al menu principal.\nIntroduce tu seleccion: ");
																		scanf("%d", &conf);	
																	}
															}
														fread(&nuevo, sizeof(tnuevo), 1, crear);
														id++;
													}
													fclose(crear);	

													break;	
												}
										}
										
									if(des == 1 && conf == 1)
										{
											system("cls");	
											printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
											printf("\t\t\t\t\t\t\t\t\tRenta.\n\n");
											printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
											printf("\t\t\t\t\t\t\tSeleccionar Libro.\n\n");
											printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
											
											id2 = 0;
											crear2 = fopen("Libros.dat", "rb");
											fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
											while(!feof(crear2))
												{
													if(libronuevo.activado2==1)
														{
															printf("ID: %d, TITULO: %s, AUTOR: %s, PRECIO: $%1.2f, F.P: %d, CANTIDAD: %d, EDITORIAL: %s, ESTATUS: %d, TIPO: %c\n", libronuevo.id2, libronuevo.titulo, libronuevo.autor,libronuevo.precio, libronuevo.anio, libronuevo.cantidad,  libronuevo.editorial,libronuevo.activado2, libronuevo.tipo[0]);
															printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
														}
													fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
													id2++;
												}
											fclose(crear2);
									
											printf("\nIngresa el ISBN que te gustaria seleccionar: "); 
											scanf("%d", &aumento2);
											
											id2 = 0;
											crear2 = fopen("Libros.dat", "rb");
											fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
											while(!feof(crear2))
												{
													if(aumento2 == libronuevo.id2)
														{
															if (libronuevo.activado2==1 && libronuevo.cantidad > 0 )
																{
																	
																	printf("Cuantos te gustaria rentar: ");
																	scanf("%d", &cantidad);
																	libronuevo.cantidad = libronuevo.cantidad - cantidad;
																		
																	if(libronuevo.cantidad > 0 )
																		{
																			printf("\a\n\nConfirmar si lo quieres leer en sala.\n");
																			printf("1)Seguir.\n2)Regresar al menu principal.\nIntroduce tu seleccion: ");
																			scanf("%d", &conf2);
																		}
																				
																}
																
															else if ((libronuevo.activado2)==0 || libronuevo.cantidad <= 1)
																{
																	conf2 = 2;
																}
														}
													fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
													id2++;
												}
											fclose(crear2);
											
									
											while(des2 == 1 && conf2 == 2)
												{
													system("cls");
													printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
													printf("\t\t\t\t\t\tSeleccion de Libros.\n\n");
													printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
													printf("\aEste libro ya no existe o aun no esta registrado, intentalo de nuevo.\n\n");
													printf("1)Seguir eligiendo.\n2)Regresar al menu principal.\nIntroduce tu seleccion: ");
													scanf("%d", &des2);
											
											switch(des2)
												{
													case 1:	
														system("cls");	
														printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
														printf("\t\t\t\t\t\tLibros Registrados.\n\n");
														printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
														
														id2 = 0;
														crear2 = fopen("Libros.dat", "rb");
														fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
														while(!feof(crear2))
															{
																if(libronuevo.activado2==1)
																	{
																		printf("ID: %d, TITULO: %s, AUTOR: %s, PRECIO: $%1.2f, F.P: %d, CANTIDAD: %d, EDITORIAL: %s, ESTATUS: %d, TIPO: %c\n", libronuevo.id2, libronuevo.titulo, libronuevo.autor,libronuevo.precio, libronuevo.anio, libronuevo.cantidad,  libronuevo.editorial,libronuevo.activado2, libronuevo.tipo[0]);
																		printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
																	}
																fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
																id2++;
															}
														fclose(crear2);
												
														printf("\nIngresa el ISBN que te gustaria seleccionar: "); 
														scanf("%d", &aumento2);
														
														id2 = 0;
														crear2 = fopen("Libros.dat", "rb");
														fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
														while(!feof(crear2))
															{
																if(aumento2 == libronuevo.id2)
																	{
																		if ((libronuevo.activado2)==1 &&  libronuevo.cantidad > 0)
																			{
																				
																				printf("Cuantos te gustaria rentar: ");
																				scanf("%d", &cantidad);
																				libronuevo.cantidad = libronuevo.cantidad - cantidad;
																		
																				if(libronuevo.cantidad > 0 )
																					{
																						printf("\a\n\nConfirmar si lo quieres leer en sala.\n");
																						printf("1)Seguir.\n2)Regresar al menu principal.\nIntroduce tu seleccion: ");
																						scanf("%d", &conf2);
																					}	
																					// Si la respuesta es afirmativa, el libro es seleccionado //	
																			}
																	}
																fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
																id2++;
															}
														fclose(crear2);

													break;
												}
											}
										}
										
									
									if(des2 == 1 && conf2 == 1 && des == 1 && conf == 1)
									{
										id2 = 0;
										crear2 = fopen("Libros.dat", "r+b");
										fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
										while(!feof(crear2))
											{
												if(aumento2 == libronuevo.id2)
													{
														libronuevo.cantidad = libronuevo.cantidad - cantidad;
														int pos = ftell(crear2)-sizeof(tlibronuevo);
														fseek(crear2, pos, SEEK_SET);
														fwrite(&libronuevo,sizeof(tlibronuevo), 1, crear2);
														break;
														
													}
												fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
												id2++;
											}
										fclose(crear2);	
										
										id3=0;
										crear3 = fopen("Rentaleer.dat", "rb");
										fread(&rentaleer, sizeof(trentaleer), 1, crear3);
										while(!feof(crear3))
										{
											fread(&rentaleer, sizeof(trentaleer), 1, crear3);
											id3++;
										}
										fclose(crear3);
											
										crear3 = fopen("Rentaleer.dat", "ab");
										rentaleer.id3 = id3;
										rentaleer.lib = aumento2;
										rentaleer.us = aumento;
										rentaleer.cant = cantidad;
										rentaleer.dias = 0;
										rentaleer.dia1 = now_tm->tm_mday;
										rentaleer.mes1 =  now_tm->tm_mon+1;
										rentaleer.anio1 = now_tm->tm_year;
										rentaleer.anio1 += 1900;
										rentaleer.tiporl[0] = 'P';
										rentaleer.estatus = 1;
										fwrite(&rentaleer, sizeof(trentaleer), 1, crear3);
										fclose(crear3);

										system("cls");
										printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
										printf("\t\t\t\t\t\tLeer en Sala.\n\n");
										printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
									
										id3=0;
										crear3 = fopen("Rentaleer.dat", "rb");
										fread(&rentaleer, sizeof(trentaleer), 1, crear3);
										while(!feof(crear3))
										{
											if(rentaleer.estatus == 1 && rentaleer.tiporl[0] == 'P')
											{
												printf("LUGAR: %d,ID: %d, ISBN: %d, CANTIDAD: %d, TIPO: %c, ESTATUS: %d, FECHA: %d/%d/%d \n", rentaleer.id3, rentaleer.us, rentaleer.lib, rentaleer.cant, rentaleer.tiporl[0], rentaleer.estatus, rentaleer.dia1, rentaleer.mes1, rentaleer.anio1);
												printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
											}
					
											fread(&rentaleer, sizeof(trentaleer), 1, crear3);
											id3++;
										}
										fclose(crear3);
									
										printf("\nPRESTAMO CON EXITO\nPresiona enter para continuar.");
										fflush(stdin);
										getchar();
									}	
									
									if(des == 2 && conf == 2)
										{
											system("cls");
											conf = 0;
											des = 1;
										}

									if(des2 == 2 && conf2 == 2)
										{
											system("cls");
											des2 = 1;
										}
								
								break;
								
								case 4:
									
									system("cls");
									printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
									printf("\t\t\t\t\t\tRegresar Libro.\n\n");
									printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
									
									id3=0;
									crear3 = fopen("Rentaleer.dat", "rb");
									fread(&rentaleer, sizeof(trentaleer), 1, crear3);
									while(!feof(crear3))
										{
											if(rentaleer.estatus == 1)
											{
												printf("LUGAR: %d, ID: %d, ISBN: %d, CANTIDAD: %d, TIPO: %c, ESTATUS: %d, FECHA: %d/%d/%d \n", rentaleer.id3, rentaleer.us, rentaleer.lib, rentaleer.cant, rentaleer.tiporl[0], rentaleer.estatus, rentaleer.dia1, rentaleer.mes1, rentaleer.anio1);
												printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
											}
					
										fread(&rentaleer, sizeof(trentaleer), 1, crear3);
										id3++;
									}
									fclose(crear3);
										
									printf("Selecciona el lugar del libro que vas a regresar: ");
									scanf("%d", &aumento3);
									
									
									id3=0;
									crear3 = fopen("Rentaleer.dat", "rb");
									fread(&rentaleer, sizeof(trentaleer), 1, crear3);
									while(!feof(crear3))
										{
											if(aumento3 == rentaleer.id3)
											{
												if ((rentaleer.estatus)==1)
													{
														printf("\a\n\nConfirmar si lo quieres regresar.\n");
														printf("1)Seguir la devolucion.\n2)Ir a un submenu.\nIntroduce tu seleccion: ");
														scanf("%d", &conf2);
														cantidad = rentaleer.cant;
														dev = rentaleer.lib;	
														tipo[0] = rentaleer.tiporl[0];			
													}
													
												else if ((rentaleer.estatus)==0)
													{
														conf2 = 2;
													}
											}
										fread(&rentaleer, sizeof(trentaleer), 1, crear3);
										id3++;
									}
									fclose(crear3);
									
									
									while(des2 == 1 && conf2 == 2)
										{
											system("cls"); // Entrara al ciclo while, y decidira que hacer en cuanto al proyecto //
											printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
											printf("\t\t\t\t\t\t\t\tRegresar Libro.\n\n");
											printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
											printf("\aEste libro ya no existe o aun no esta registrado, intentalo de nuevo.\n\n");
											printf("1)Seguir eligiendo.\n2)Regresar al menu principal.\nIntroduce tu seleccion: ");
											scanf("%d", &des2);
											
											// Si se desea la primera opcion entrara y seleccionara un nuevo libro //
										
										switch(des2)
											{
												case 1:	
													system("cls");	
													printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
													printf("\t\t\t\t\t\tRegresar Libros.\n\n");
													printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
													
													id3=0;
													crear3 = fopen("Rentaleer.dat", "rb");
													fread(&rentaleer, sizeof(trentaleer), 1, crear3);
													while(!feof(crear3))
														{
															if(rentaleer.estatus == 1)
															{
																printf("LUGAR: %d, ID: %d, ISBN: %d, CANTIDAD: %d, TIPO: %c, ESTATUS: %d, FECHA: %d/%d/%d \n", rentaleer.id3, rentaleer.us, rentaleer.lib, rentaleer.cant, rentaleer.tiporl[0], rentaleer.estatus, rentaleer.dia1, rentaleer.mes1, rentaleer.anio1);
																printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
															}
									
														fread(&rentaleer, sizeof(trentaleer), 1, crear3);
														id3++;
													}
													fclose(crear3);
														
													printf("\nIngresa el id que te gustaria regresar: "); // Elimina a los libros que tengan el id comentado//
													scanf("%d", &aumento3);
													
													id3=0;
													crear3 = fopen("Rentaleer.dat", "rb");
													fread(&rentaleer, sizeof(trentaleer), 1, crear3);
													while(!feof(crear3))
														{
															if(aumento3 == rentaleer.id3)
															{
																if ((rentaleer.estatus)==1)
																	{
																		printf("\a\n\nConfirmar si lo quieres regresar.\n");
																		printf("1)Seguir.\n2)Regresar al menu principal.\nIntroduce tu seleccion: ");
																		scanf("%d", &conf2);
																		cantidad = rentaleer.cant;
																		dev = rentaleer.lib;
																		tipo[0] = rentaleer.tiporl[0];	
																	}
															}
									
														fread(&rentaleer, sizeof(trentaleer), 1, crear3);
														id3++;
													}
													fclose(crear3);
														// Volvera a preguntar si quiere ser eliminado, o no //
												break;
											}
										}
										
								// Si el caso es positivo, se eliminaran los libros //
								
									if(des2 == 1 && conf2 == 1)
										{
											id3 = 0;
											crear3 = fopen("Rentaleer.dat", "r+b");
											fread(&rentaleer, sizeof(trentaleer), 1, crear3);
											while(!feof(crear3))
												{
													if(aumento3 == rentaleer.id3)
														{
															rentaleer.estatus = 0;
															system("cls");
															adeudo = rentaleer.dias;
															int pos = ftell(crear3)-sizeof(trentaleer);
															fseek(crear3, pos, SEEK_SET);
															fwrite(&rentaleer,sizeof(trentaleer), 1, crear3);
															break;
														}
													fread(&rentaleer, sizeof(trentaleer), 1, crear3);
													id3++;
												}
											fclose(crear3);

											if(tipo[0] == 'R')
												{
													system("cls");
													printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
													printf("\t\t\t\t\t\tRegresar Libro.\n\n");
													printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
													
													id2 = 0;
													crear2 = fopen("Libros.dat", "r+b");
													fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
													while(!feof(crear2))
														{
															if(dev == libronuevo.id2)
																{
																	libronuevo.cantidad = libronuevo.cantidad + cantidad;
																	int pos = ftell(crear2)-sizeof(tlibronuevo);
																	fseek(crear2, pos, SEEK_SET);
																	fwrite(&libronuevo,sizeof(tlibronuevo), 1, crear2);
																	break;
																	
																}
															fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
															id2++;
														}
													fclose(crear2);	
													
													id2 = 0;
													crear2 = fopen("Libros.dat", "rb");
													fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
													while(!feof(crear2))
														{
															if(libronuevo.activado2==1)
																{
																	printf("ID: %d, TITULO: %s, AUTOR: %s, PRECIO: $%1.2f, F.P: %d, CANTIDAD: %d, EDITORIAL: %s, ESTATUS: %d, TIPO: %c\n", libronuevo.id2, libronuevo.titulo, libronuevo.autor,libronuevo.precio, libronuevo.anio, libronuevo.cantidad,  libronuevo.editorial,libronuevo.activado2, libronuevo.tipo[0]);
																	printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
																}
															fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
															id2++;
														}
													fclose(crear2);
														
													printf("\nACTUALIZACION EXITOSA\nPresiona enter para continuar.");
													fflush(stdin);
													getchar();
													
													system("cls");
													
													printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
													printf("\t\t\t\t\t\t\t\tPago por devolucion de libros.\n\n");
													printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
													printf("\t\t\t\t\t\t\t\t\tCostos.\n\n");
													printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
													printf("\t\t\t\t\t\tDias\t\t\t\t\t\tCantidad\n\n");
													printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
													printf("\t\t\t\t\t\t1\t\t\t\t\t\t$10\n\n");
													printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
													printf("\t\t\t\t\t\t2\t\t\t\t\t\t$15\n\n");
													printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
													printf("\t\t\t\t\t\t3\t\t\t\t\t\t$20\n\n");
													printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
													printf("\t\t\t\t\t\tN\t\t\t\t\t\tIncrementar $3 por dia\n\n");
													printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
													
													// En esta seccion comenzara a seleccionar la cantidad de dias que tardo para devolver el mencionado libro, tras esto, comenzara ejecutar esta seccion los pagos que se deveran de realizar //
													id3 = 0;
													crear3 = fopen("Rentaleer.dat", "r+b");
													fread(&rentaleer, sizeof(trentaleer), 1, crear3);
													while(!feof(crear3))
														{
															if(aumento3 == rentaleer.id3)
																{
																	printf("Ingresa los dias que tardo para devolverlos: ");
																	fflush(stdin);
																	scanf("%d", &rentaleer.dias);
																	system("cls");
																	adeudo = rentaleer.dias;
																	int pos = ftell(crear3)-sizeof(trentaleer);
																	fseek(crear3, pos, SEEK_SET);
																	fwrite(&rentaleer,sizeof(trentaleer), 1, crear3);
																	break;
																}
															fread(&rentaleer, sizeof(trentaleer), 1, crear3);
															id3++;
														}
													fclose(crear3);
													
													if(adeudo==1)
														{
															
															printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
															printf("\t\t\t\t\t\t\t\tBiblioteca Bisonte.\n\n");
															printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
															printf("\t\t\t\t\t\t\t\tCANTIDAD: %d\n", cantidad);
															printf("\t\t\t\t\t\t\t\tPRECIO: $%d\n", mult1(cantidad));
															printf("\t\t\t\t\t\t\t\tTOTAL: $%d\n", mult1(cantidad));
															printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
															printf("\nPAGO CON EXITO\nPresiona enter para continuar.");
															fflush(stdin);
															getchar();
														}
														
													else if(adeudo==2)
														{
															printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
															printf("\t\t\t\t\t\t\t\tBiblioteca Bisonte.\n\n");
															printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
															printf("\t\t\t\t\t\t\t\tCANTIDAD: %d\n",cantidad);
															printf("\t\t\t\t\t\t\t\tPRECIO: $%d\n", mult2(cantidad));
															printf("\t\t\t\t\t\t\t\tTOTAL: $%d\n", mult2(cantidad));
															printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
															printf("\nPAGO CON EXITO\nPresiona enter para continuar.");
															fflush(stdin);
															getchar();
														}
														
													else if((adeudo) == 3)
														{
															printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
															printf("\t\t\t\t\t\t\t\tBiblioteca Bisonte.\n\n");
															printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
															printf("\t\t\t\t\t\t\t\tCANTIDAD: %d\n", cantidad);
															printf("\t\t\t\t\t\t\t\tPRECIO: $%d\n", mult3(cantidad));
															printf("\t\t\t\t\t\t\t\tTOTAL: $%d\n\n", mult3(cantidad));
															printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
															printf("\nPAGO CON EXITO\nPresiona enter para continuar.");
															fflush(stdin);
															getchar();
														}
														
													else if((adeudo) > 3)
														{
															printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
															printf("\t\t\t\t\t\t\t\tBiblioteca Bisonte.\n\n");
															printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
															printf("\t\t\t\t\t\t\t\tCANTIDAD: $%d\n", (cantidad));
															printf("\t\t\t\t\t\t\t\tPRECIO $%d\n", mult4((cantidad),(adeudo)));
															printf("\t\t\t\t\t\t\t\tTOTAL: $%d\n\n", mult4((cantidad),(adeudo)));
															printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
															printf("\nPAGO CON EXITO\nPresiona enter para continuar.");
															fflush(stdin);
															getchar();
														}
												}
											
											else if(tipo[0] == 'P')
												{
													system("cls");
													printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
													printf("\t\t\t\t\t\tRegresar Libro.\n\n");
													printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
													
													id2 = 0;
													crear2 = fopen("Libros.dat", "r+b");
													fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
													while(!feof(crear2))
														{
															if(dev == libronuevo.id2)
																{
																	libronuevo.cantidad = libronuevo.cantidad + cantidad;
																	int pos = ftell(crear2)-sizeof(tlibronuevo);
																	fseek(crear2, pos, SEEK_SET);
																	fwrite(&libronuevo,sizeof(tlibronuevo), 1, crear2);
																	break;
																	
																}
															fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
															id2++;
														}
													fclose(crear2);	
													
													id2 = 0;
													crear2 = fopen("Libros.dat", "rb");
													fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
													while(!feof(crear2))
														{
															if(libronuevo.activado2==1)
																{
																	printf("ID: %d, TITULO: %s, AUTOR: %s, PRECIO: $%1.2f, F.P: %d, CANTIDAD: %d, EDITORIAL: %s, ESTATUS: %d, TIPO: %c\n", libronuevo.id2, libronuevo.titulo, libronuevo.autor,libronuevo.precio, libronuevo.anio, libronuevo.cantidad,  libronuevo.editorial,libronuevo.activado2, libronuevo.tipo[0]);
																	printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
																}
															fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
															id2++;
														}
													fclose(crear2);
											
													printf("\nACTUALIZACION EXITOSA\nPresiona enter para continuar.");
													fflush(stdin);
													getchar();	
												}
										}
										
									// Si no, volvera al menu principal //
									
									else if(des2 == 2 && conf2 == 2)
										{
											cantidad = 0;
											system("cls");
											des2 = 1;
										}
								break;
								
								default :
									
								break;
								
							}
				break;
				
					
				case 4: 		
						system("cls");
						printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
						printf("\t\t\t\t\t\t\t\t\tClientes.\n\n");
						printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");	
						printf("1)Consulta por Cliente.\n2)Consulta por Libro.\n3)Consulta de Movimientos de Libros.\n4)Regresar al menu principal\n\nIngresa tu opcion: ");
						scanf("%d", &consulta);
						
						switch(consulta)
							{
								case 1: 	
									system("cls"); //En esta parte Te da la opcion de elegir a los clientes por su id //
									printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
									printf("\t\t\t\t\t\t\tClientes Registrados.\n\n");
									printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
									
									id=0;									
									crear = fopen("Clientes.dat", "rb");
									fread(&nuevo, sizeof(tnuevo), 1, crear);
									while(!feof(crear))
									{
										if(nuevo.activado==1)
											{
												printf("ID: %d, NOMBRE: %s, CORREO: %s, TELEFONO: %s, DIRECCION: %s, ESTATUS: %d\n", nuevo.id, nuevo.nom, nuevo.correo, nuevo.tel, nuevo.dir, nuevo.activado);
												printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");	
											}
										fread(&nuevo, sizeof(tnuevo), 1, crear);
										id++;
									}
									fclose(crear);
									
									//Te muestra a los clientes que estan activados //
									
									printf("\nIngresa el id que te gustaria consultar: "); // Muestra a los clientes que tengan el id comentado//
									scanf("%d", &aumento);
									
									// Te pedira una confirmacion para la muestra de dichos clientes //
									
									id=0;									
									crear = fopen("Clientes.dat", "rb");
									fread(&nuevo, sizeof(tnuevo), 1, crear);
									while(!feof(crear))
									{
										if(aumento == nuevo.id)
											{
												if ((nuevo.activado)==1) // Dependiendo de su estatus, entrara o no entrara al menu, ya que la confirmacion hace que vaya a algun punto //
													{
														printf("\a\n\nConfirmar si lo quieres consultar.\n");
														printf("1)Seguir con la consulta.\n2)Ir a un submenu.\nIntroduce tu seleccion: ");
														scanf("%d", &conf);			
													}
													
												else if ((nuevo.activado)==0)
													{
														conf = 2;
													}			
											}
										fread(&nuevo, sizeof(tnuevo), 1, crear);
										id++;
									}
									fclose(crear);
									
									while(des == 1 && conf == 2) 
										{
											system("cls");
											printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
											printf("\t\t\t\t\t\t\tConsulta de Clientes.\n\n");
											printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
										
											// Si en dado caso, el dato que ingreso para consultar al cliente aun no existe o ya fue eliminado ingresara a este menu //
											
											printf("\aElige otro cliente o ingresa lo que te gustaria hacer.\n");
											printf("1)Seguir eligiendo.\n2)Regresar al menu principal.\nIntroduce tu seleccion: ");
											scanf("%d", &des);
											
											// Dependera de la desicion que tome el usuario es lo que hara el programa, saldra o entrara a volver a elegir otro cliente //
											
											switch(des)
												{
													case 1:
														system("cls");
														printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
														printf("\t\t\t\t\t\t\tClientes Registrados.\n\n");
														printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
														
														// Si desea seguir eligiendo volvera a repetir el proceso pasado en un bucle //
														
														id=0;									
														crear = fopen("Clientes.dat", "rb");
														fread(&nuevo, sizeof(tnuevo), 1, crear);
														while(!feof(crear))
														{
															if(nuevo.activado==1)
																{
																	printf("ID: %d, NOMBRE: %s, CORREO: %s, TELEFONO: %s, DIRECCION: %s, ESTATUS: %d\n", nuevo.id, nuevo.nom, nuevo.correo, nuevo.tel, nuevo.dir, nuevo.activado);
																	printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");	
																}
															fread(&nuevo, sizeof(tnuevo), 1, crear);
															id++;
														}
														fclose(crear);
														
														printf("\nIngresa el id que te gustaria consultar: "); // Mostrara a los clientes que tengan el id comentado//
														scanf("%d", &aumento);
														
														id=0;									
														crear = fopen("Clientes.dat", "rb");
														fread(&nuevo, sizeof(tnuevo), 1, crear);
														while(!feof(crear))
														{
															if(aumento == nuevo.id)
																{
																	if ((nuevo.activado)==1)
																		{
																			printf("\a\n\nConfirmar si lo quieres consultar.\n");
																			printf("1)Seguir.\n2)Regresar al menu principal.\nIntroduce tu seleccion: ");
																			scanf("%d", &conf);	 //Te volvera a preguntar que quieres hacer si esta activado //
																		}
																}
															fread(&nuevo, sizeof(tnuevo), 1, crear);
															id++;
														}
														fclose(crear);
														
													break;	
												}
											
										}
										
									if(des == 1 && conf == 1)
										{
											system("cls");
											
											id=0;	// Te los imprime usando rb, r es lectura y b es para archivos binarios //								
											crear = fopen("Clientes.dat", "rb");
											fread(&nuevo, sizeof(tnuevo), 1, crear);
											while(!feof(crear))
												{
													if(aumento == nuevo.id)
														{
															printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
															printf("\t\t\t\t\t\t\tConsulta de Clientes\n\n");
															printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
															printf("ID: %d\n", nuevo.id);
															printf("Nombre: %s\n", nuevo.nom);
															printf("Correo: %s\n", nuevo.correo);
															printf("Direccion: %s\n", nuevo.dir);
															printf("Telefono: %s\n", nuevo.tel);
															printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
															printf("\t\t\t\t\t\t\tLibros Rentados\n\n");
															printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
														}
													fread(&nuevo, sizeof(tnuevo), 1, crear);
													id++;
												}
											fclose(crear);
											
											id3=0;
											crear3 = fopen("Rentaleer.dat", "rb");
											fread(&rentaleer, sizeof(trentaleer), 1, crear3);
											while(!feof(crear3))
												{
													if(aumento == rentaleer.us)
														{
															if (rentaleer.estatus==0 && rentaleer.tiporl[0]== 'R')
																{
																	printf("ISBN: %d, FECHA DE RENTA: %d/%d/%d, NUMERO DE DIAS: %d\n", rentaleer.lib , rentaleer.dia1, rentaleer.mes1, rentaleer.anio1 ,rentaleer.dias);
																	printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
																}
														}
									
													fread(&rentaleer, sizeof(trentaleer), 1, crear3);
													id3++;
												}
											fclose(crear3);
												
											printf("\nCONSULTA CON EXITO\nPresiona enter para continuar.");
											fflush(stdin);
											getchar();
											des = 1;
											conf = 0;
										}
									
									// Si en dado caso no muestra a nadie, los valores seran estos y volveremos al principio del programa // 
									else if(des == 2 && conf == 2)
										{
											system("cls");
											conf = 0;
											des = 1;
										}
									
								break; 
								
								case 2: system("cls"); //Son tres formas de consultar los libros, por nombre, titulo e ISBN, aqui mostrara algunos puntos del libro //
										printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
										printf("\t\t\t\t\t\t\t\t\tConsulta por Libro.\n\n");
										printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");	
										printf("Como te gustaria buscar tu libro.\n1)Por Titulo.\n2)Por Autor.\n3)Por ISBN.\n4)Regresar al menu principal\n\nIngresa tu opcion: ");
										scanf("%d", &consulta2);
										switch(consulta2)
											{
												case 1: system("cls");
														printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
														printf("\t\t\t\t\t\t\t\t\tConsulta por Titulo.\n\n");
														printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");	
														
														printf("Ingresa el Titulo del Libro: ");
														fflush(stdin);
														gets(conom);
														
														system("cls");
														printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
														printf("\t\t\t\t\t\t\t\t\tConsulta por Libro.\n\n");
														printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");	
														
														id2 = 0;
														crear2 = fopen("Libros.dat", "rb");
														fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
														while(!feof(crear2))
															{
																if(strcmp(conom,libronuevo.titulo)==0 && libronuevo.tipo[0]== 'R' && libronuevo.activado2 == 1)
																	{
																		printf("TITULO: %s, AUTOR: %s, PRECIO: $%1.2f, F.P: %d, ISBM: %d, C.R.: %d, C.V.: 0, C.P.S: %d\n", libronuevo.titulo, libronuevo.autor,libronuevo.precio, libronuevo.anio, id2, libronuevo.cantidad, libronuevo.cantidad);
																		printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
																	}
																	
																else if(strcmp(conom,libronuevo.titulo)==0 && libronuevo.tipo[0]== 'V' && libronuevo.activado2 == 1)
																	{
																		printf("TITULO: %s, AUTOR: %s, PRECIO: $%1.2f, F.P: %d, ISBM: %d, C.R.: 0, C.V.: %d, C.P.S: %d\n", libronuevo.titulo, libronuevo.autor,libronuevo.precio, libronuevo.anio, id2, libronuevo.cantidad, libronuevo.cantidad);
																		printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
																	}
																	
																fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
																id2++;
															}
														fclose(crear2);
															
														printf("\nCONSULTA CON EXITO\nPresiona enter para continuar.");
														fflush(stdin);
														getchar();
												break;
													
												case 2: system("cls");
														printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
														printf("\t\t\t\t\t\t\t\t\tConsulta por Autor.\n\n");
														printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");	
														
														printf("Ingresa el Autor del Libro: ");
														fflush(stdin);
														gets(cread);
														
														system("cls");
														printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
														printf("\t\t\t\t\t\t\t\t\tConsulta por Autor.\n\n");
														printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");	
														
														id2 = 0;
														crear2 = fopen("Libros.dat", "rb");
														fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
														while(!feof(crear2))
															{
																if(strcmp(cread,libronuevo.autor)==0 && libronuevo.tipo[0]== 'R' && libronuevo.activado2 == 1)
																	{
																		printf("TITULO: %s, AUTOR: %s, PRECIO: $%1.2f, F.P: %d, ISBM: %d, C.R.: %d, C.V.: 0, C.P.S: %d\n", libronuevo.titulo, libronuevo.autor,libronuevo.precio, libronuevo.anio, id2, libronuevo.cantidad, libronuevo.cantidad);
																		printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
																	}
																	
																else if(strcmp(cread,libronuevo.autor)==0 && libronuevo.tipo[0]== 'V' && libronuevo.activado2 == 1)
																	{
																		printf("TITULO: %s, AUTOR: %s, PRECIO: $%1.2f, F.P: %d, ISBM: %d, C.R.: 0, C.V.: %d, C.P.S: %d\n", libronuevo.titulo, libronuevo.autor,libronuevo.precio, libronuevo.anio, id2, libronuevo.cantidad, libronuevo.cantidad);
																		printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
																	}
																	
																fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
																id2++;
															}
														fclose(crear2);
														
														printf("\nCONSULTA CON EXITO\nPresiona enter para continuar.");
														fflush(stdin);
														getchar();
												break;
												
												case 3: system("cls");
														printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
														printf("\t\t\t\t\t\t\t\t\tConsulta por ISBN.\n\n");
														printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");	
														
														printf("Ingresa el ISBN del Libro: ");
														fflush(stdin);
														scanf("%d", &elec);
														system("cls");
														
														printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
														printf("\t\t\t\t\t\t\t\t\tConsulta por ISBN.\n\n");
														printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");	
														
														id2 = 0;
														crear2 = fopen("Libros.dat", "rb");
														fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
														while(!feof(crear2))
															{
																if(libronuevo.id2 == elec && libronuevo.tipo[0]== 'R' && libronuevo.activado2 == 1)
																	{
																		printf("TITULO: %s, AUTOR: %s, PRECIO: $%1.2f, F.P: %d, ISBM: %d, C.R.: %d, C.V.: 0, C.P.S: %d\n", libronuevo.titulo, libronuevo.autor,libronuevo.precio, libronuevo.anio, id2, libronuevo.cantidad, libronuevo.cantidad);
																		printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
																	}
																	
																else if(libronuevo.id2 == elec && libronuevo.tipo[0]== 'V' && libronuevo.activado2 == 1)
																	{
																		printf("TITULO: %s, AUTOR: %s, PRECIO: $%1.2f, F.P: %d, ISBM: %d, C.R.: 0, C.V.: %d, C.P.S: %d\n", libronuevo.titulo, libronuevo.autor,libronuevo.precio, libronuevo.anio, id2, libronuevo.cantidad, libronuevo.cantidad);
																		printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
																	}
																	
																fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
																id2++;
															}
														fclose(crear2);
															
														printf("\nCONSULTA CON EXITO\nPresiona enter para continuar.");
														fflush(stdin);
														getchar();
												break;
												
												default:
												break;	
											}
								break; 
								
								case 3:
									
									system("cls");	
								
									// De forma parecida, pedira el id del libro, el cual sera seleccionado y se analizara si ya fue eliminado o aun no //
									
									printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
									printf("\t\t\t\t\t\t\t\tMovimientos de Libros.\n\n");
									printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
										
									id2 = 0;
									crear2 = fopen("Libros.dat", "rb");
									fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
									while(!feof(crear2))
										{
											if(libronuevo.activado2==1)
												{
													printf("ID: %d, TITULO: %s, AUTOR: %s, PRECIO: $%1.2f, F.P: %d, CANTIDAD: %d, EDITORIAL: %s, ESTATUS: %d, TIPO: %c\n", libronuevo.id2, libronuevo.titulo, libronuevo.autor,libronuevo.precio, libronuevo.anio, libronuevo.cantidad,  libronuevo.editorial,libronuevo.activado2, libronuevo.tipo[0]);
													printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
												}
											fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
											id2++;
										}
									fclose(crear2);
								
									printf("\nIngresa el ISBN que te gustaria consultar: "); 
									scanf("%d", &aumento2);
									
									// Si el libro existe, preguntara que si quiere que sea consultado, o si reingresara a un submenu para saber que hacer //
									
									id2 = 0;
									crear2 = fopen("Libros.dat", "rb");
									fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
									while(!feof(crear2))
										{
											if(aumento2 == libronuevo.id2)
												{
													if (libronuevo.activado2==1)
														{
															printf("\a\n\nConfirmar si lo quieres consultar.\n");
															printf("1)Seguir con la consulta.\n2)Ir a un submenu.\nIntroduce tu seleccion: ");
															scanf("%d", &conf2);			
														}
															
													else if ((libronuevo.activado2)==0)
														{
															conf2 = 2;
														}
												}
											fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
											id2++;
										}
									fclose(crear2);
								
									while(des2 == 1 && conf2 == 2)
										{
											system("cls");
											
											// Entrara al ciclo while, y decidira que hacer en cuanto al proyecto //
											
											printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
											printf("\t\t\t\t\t\t\t\tConsulta de Libros.\n\n");
											printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
											printf("\aEste libro ya no existe o aun no esta registrado, intentalo de nuevo.\n\n");
											printf("1)Seguir eligiendo.\n2)Regresar al menu principal.\nIntroduce tu seleccion: ");
											scanf("%d", &des2);
											
											// Si se desea la primera opcion entrara y seleccionara un nuevo libro //
										
										switch(des2)
											{
												case 1:	
													system("cls");	
													printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
													printf("\t\t\t\t\t\tLibros Registrados.\n\n");
													printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
													
													id2 = 0;
													crear2 = fopen("Libros.dat", "rb");
													fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
													while(!feof(crear2))
														{
															if(libronuevo.activado2==1)
																{
																	printf("ID: %d, TITULO: %s, AUTOR: %s, PRECIO: $%1.2f, F.P: %d, CANTIDAD: %d, EDITORIAL: %s, ESTATUS: %d, TIPO: %c\n", libronuevo.id2, libronuevo.titulo, libronuevo.autor,libronuevo.precio, libronuevo.anio, libronuevo.cantidad,  libronuevo.editorial,libronuevo.activado2, libronuevo.tipo[0]);
																	printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
																}
															fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
															id2++;
														}
													fclose(crear2);
														
													printf("\nIngresa el ISBN que te gustaria ver sus movimientos: "); // Muestra a los libros que tengan el id comentado//
													scanf("%d", &aumento2);
													
													id2 = 0;
													crear2 = fopen("Libros.dat", "rb");
													fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
													while(!feof(crear2))
														{
															if(aumento2 == libronuevo.id2)
																{
																	if ((libronuevo.activado2)==1)
																		{
																			printf("\a\n\nConfirmar si lo ver.\n");
																			printf("1)Seguir.\n2)Regresar al menu principal.\nIntroduce tu seleccion: ");
																			scanf("%d", &conf2);	
																		}
																}
															fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
															id2++;
														}

														// Volvera a preguntar si quiere ser mostrado, o no //
												break;
												
												default:
												break;
											}
										}
										
									// Si el caso es positivo, se eliminaran los libros //
									if(des2 == 1 && conf2 == 1)
										{
											
											system("cls");	
											
											id2 = 0;
											crear2 = fopen("Libros.dat", "rb");
											fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
											while(!feof(crear2))
												{
													if(aumento2 == libronuevo.id2)
														{
															printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
															printf("\t\t\t\t\t\t\t\t\tMovimientos de Libros.\n\n");
															printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");	
															printf("ISBN: %d.\n", libronuevo.id2);
															printf("Titulo: %s.\n", libronuevo.titulo);
															printf("Autor: %s.\n", libronuevo.autor);
															printf("Autor: %s.\n", libronuevo.editorial);		
														}
														
													fread(&libronuevo, sizeof(tlibronuevo), 1, crear2);
													id2++;
												}
											fclose(crear2);
						
											printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
											printf("\t\t\t\t\t\t\t\tMovimientos.\n\n");
											printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");	
											
											id3=0;
											crear3 = fopen("Rentaleer.dat", "rb");
											fread(&rentaleer, sizeof(trentaleer), 1, crear3);
											while(!feof(crear3))
												{
													if(aumento2 == rentaleer.lib)
														{
															printf("ID CLIENTE: %d, FECHA: %d/%d/%d, TIPO: %c\n", rentaleer.us,  rentaleer.dia1, rentaleer.mes1, rentaleer.anio1 , rentaleer.tiporl[0]);
															printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
														}
									
													fread(&rentaleer, sizeof(trentaleer), 1, crear3);
													id3++;
												}
											fclose(crear3);
											
											id4=0;
											crear4 = fopen("Venta.dat", "rb");
											fread(&venta, sizeof(tventa), 1, crear4);
											while(!feof(crear4))
												{
													if(aumento2 == venta.lib2)
														{
															printf("ID CLIENTE: N/A, FECHA: %d/%d/%d, TIPO: V\n",  venta.dia2, venta.mes2, venta.anio2);
															printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
														}
									
													fread(&venta, sizeof(tventa), 1, crear4);
													id4++;
												}
											fclose(crear4);
												
											printf("\nSi en tipo es R, es Renta, si es V es Venta, si es P, es Prestamo.\nCONSULTA CON EXITO\nPresiona enter para continuar.");
											fflush(stdin);
											getchar();
											
										}
										
									// Si no, volvera al menu principal //
									
									else if(des2 == 2 && conf2 == 2)
										{
											system("cls");
											des2 = 1;
										}
								break;
								
								default:
									
								break;	
							}	
					break;	
						
				case 5: // Salida del programa //
						if(usuario==1897962)
					{
						system("cls");
						printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
						printf("Adios Juan Manuel Martinez Ramirez.\t\t\t\t\t\t\t%s", ctime(&tiempo));
						printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
					}
					
						if(usuario==1842829)
					{
						system("cls");
						printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
						printf("Adios Ana Lizbeth Dominguez Garza.\t\t\t\t\t\t\t        %s", ctime(&tiempo));
						printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
					}
					
						if(usuario==1941436)
					{
						system("cls");
						printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
						printf("Adios Angel Ledezma Zavala.\t\t\t\t\t\t\t\t%s", ctime(&tiempo));
						printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
					}
					
						if(usuario==1907995)
					{
						system("cls");
						printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
						printf("Adios Luis Armando Villanueva Garcia.\t\t\t\t\t\t\t        %s", ctime(&tiempo));
						printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
						
					}	
				break;
				
				default: intentos = intentos+1; // Si despues de 3 intentos no seleccionas uno de los numeros correctos, automaticamente el programa finaliza //
							if(intentos==3)
							{
								system("cls");
								printf("\t\t\t\t\t\t\aSE CIERRA SESION.\n\n");
								return 0;
							}
				break;
			}
		}while(opcion != 5);
	
	
	return 0;
}


int mult1(int y)
{
	return (y*10);
}

int mult2(int x)
{
	return (x*15);
}

int mult3(int j)
{
	return (j*20);
}

int mult4(int z, int e)
{
	return (20*(z)+((z)*(e)*3));
}





