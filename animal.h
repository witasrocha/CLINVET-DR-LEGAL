// struct "exemplo" possui dois campos
typedef struct animal
{
	int v; // inteiro "v"	
	char*nomeAnimal; 
	char*especie; 
	char*raca; 
	int idade; 
	char*nomeProprietario; 
	float conta; 
	char*telefone; 
	struct animal *prox; // ponteiro para o pr�ximo elemento
	
} t_animal;


// vari�veis ponteiros globais que guardam refer�ncia
// para a cabe�a da lista e para o n� corrente
// cabeca da lista encadeada (come�a com NULL)
t_animal *cabeca = NULL;
t_animal *corrente = NULL;
//t_animal *cabeca;
//t_animal *corrente;


// fun��o para criar uma lista
// recebe um valor inteiro e retorna um ponteiro do tipo t_animal
t_animal * criar_lista(int valor, char*nomeanimal, char*especie, char*raca, int idade, char*nomeproprietario, float conta, char*telefone)
{
    
	// aloca espa�o em mem�ria
	t_animal * p = (t_animal*)malloc(sizeof(t_animal));	
    p->nomeAnimal = malloc(255); 
    p->especie = malloc(255); 
    p->raca = malloc(255); 
    p->nomeProprietario = malloc(255); 
    p->telefone = malloc(11); 

	// verifica se houve falha na aloca��o de mem�ria
	if(p == NULL)
	{
		printf("\n Falha ao alocar memoria\n");
		return NULL;
	}
    
    
	// se chegou aqui � porque foi feita a aloca��o com sucesso
	p->v = valor; // atribui o valor passado	
    p->nomeAnimal= nomeanimal;    
	p->especie= especie; 
	p->raca= raca; 
	p->idade=idade; 
	p->nomeProprietario= nomeproprietario; 
	p->conta=conta; 
	p->telefone= telefone; 
	p->prox = NULL; // o pr�ximo � NULL

	// faz a cabeca e o corrente apontar para p
	cabeca = corrente = p;
	// retorna o ponteiro alocado
	return p;
}


// fun��o que adiciona um elemento � lista
// recebe a cabeca e o elemento a ser adicionado
// o elemento � inserido no FINAL da lista
t_animal* adicionar_lista(int v, char*nomeanimal, char*especie, char*raca, int idade, char*nomeproprietario, float conta, char*telefone)
{  
	// verifica se a cabeca � NULL (lista vazia), se for NULL,
	// ent�o retorna o retorno da fun��o criar_lista

	if(cabeca == NULL)
	{
		return criar_lista(v, nomeanimal, especie, raca, idade, nomeproprietario, conta, telefone);
	}

	// se chegou aqui � porque a lista N�O � vazia
	// aloca espa�o em mem�ria
	t_animal * p = (t_animal*)malloc(sizeof(t_animal));	
	p->nomeAnimal = malloc(255); 
    p->especie = malloc(255); 
    p->raca = malloc(255); 
    p->nomeProprietario = malloc(255); 
    p->telefone = malloc(11); 
    
	// verifica se houve falha na aloca��o de mem�ria
	if(p == NULL)
	{
		printf("\nFalha ao alocar memoria\n");
		return NULL;
	}
	

     
	// atribui valores
	p->v = v;
	
    p->nomeAnimal= nomeanimal;    
	p->especie= especie; 
	p->raca= raca; 
	p->idade=idade; 
	p->nomeProprietario= nomeproprietario; 
	p->conta=conta; 
	p->telefone= telefone; 
	p->prox = NULL;

	// insere no FINAL da lista (obs.: tamb�m poderia ser no in�cio)
	// aqui ser� feita a inser��o no final,	
	// para inser��o no final, fazemos com que o pr�ximo do n�
	// corrente aponte para o "p"
	corrente->prox = p;
	// o corrente passar a ser o "p"
	corrente = p;

	// retorna o ponteiro alocado
	return p;
}


// fun��o que imprime a lista
void imprimir_lista()
{
	//fflush(stdout);

	// vari�vel ponteiro "aux" para percorrer a lista
	// inicialmente aponta para a "cabeca"
	t_animal *aux = cabeca;
 	printf("\n %8s \n","XXXXXXXXXXXXXXXXXXXXXXXXXX LISTAGEM DE ANIMAIS XXXXXXXXXXXXXXXXXXXXXXXXXX"  ); 
    //printf("%8s\t%8s\t%8s\t%8s\t%8s\t%8s\t%8s\t%8s\n","ID","ANIMAL","ESPECIE","RACA","IDADE","PROPRIETARIO","CONTA","TELEFONE"  );     
	// enquanto "aux" for diferente de NULL
	while(aux != NULL)
	{
		// imprime o valor
		//printf("%8d\t%8s\t%8s\t%8s\t%8d\t%8s\t%8f\t%8s\n", aux->v, aux->nomeAnimal, aux->especie, aux->raca,aux->idade,aux->nomeProprietario,aux->conta,aux->telefone);
		printf("\n %8s \n","XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"  ); 
		printf("ID: %8d\n", aux->v);
		printf("NOME: %8s\n", aux->nomeAnimal);
		printf("ESPECIE: %8s\n", aux->especie);
		printf("RACA: %8s\n", aux->raca);
		printf("IDADE %8d\n", aux->idade);
		printf("DONO: %8s\n", aux->nomeProprietario);
		printf("CONTA: %8f\n", aux->conta);
		printf("TELEFONE: %8s\n", aux->telefone);
		printf("\n %8s \n","XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"  ); 
		
		
		// aponta para o pr�ximo elemento da lista
		aux = aux->prox;
	}
}


// fun��o para verificar se a lista est� vazia
// retorna 1 se estiver vazia e 0 caso contr�rio
int lista_vazia()
{
	// se cabeca for NULL, ent�o a lista est� vazia
	if(cabeca == NULL)
		return 1;
	return 0;
}


// fun��o para buscar um elemento na lista
// essa fun��o recebe o valor a ser buscado e um ponteiro para ponteiro "ant"
// o "ant" servir� para guardarmos o anterior do elemento encontrado, pois
// iremos utilizar na remo��o, assim fica mais otimizado para n�o ter que
// percorrer a lista novamente pois precisa-se do elemento anterior ao elemento
// que ir� ser removido para ajustar corretamente a lista
// retorna o ponteiro para o elemento encontrado ou NULL se n�o encontrar
t_animal * buscar_elemento(int v, t_animal **ant)
{
	// se a lista estiver vazia, ent�o n�o possui elementos,
	// portanto, retorna 0 indicando que N�O achou.
	if(lista_vazia() == 1)
		return NULL;

	// vari�vel "p" para percorrer a lista
	t_animal *p = cabeca;
	// vari�vel "aux_ant" para guardar o anterior
	t_animal *aux_ant = NULL;
	// flag "achou" que indica se achou o elemento
	int achou = 0;

	// percorre a lista
	while(p != NULL)
	{
		// se achou, ent�o retorna 1
		if(p->v == v)
		{
			achou = 1;
			break;
		}
		// atualiza o "aux_ant"
		aux_ant = p;
		// aponta para o pr�ximo
		p = p->prox;
	}

	// verifica se achou
	if(achou == 1)
	{
		// se "ant" for diferente de NULL
		if(ant)
			*ant = aux_ant; // guarda "aux_ant"
		return p;
	}

	// se chegou aqui, ent�o n�o achou
	return NULL;
}

// fun��o que remove um elemento da lista
// retorna 1 se conseguiu remover e 0 caso contr�rio
int remover_elemento(int v)
{
	// vari�vel que guarda a refer�ncia para o elemento anterior
	// do elemento que vai ser removido
	t_animal *ant = NULL;

	// busca pelo elemento a ser removido
	// passa a refer�ncia para o "ant" (ponteiro para ponteiro)
	// "elem" � o elemento que ser� removido
	t_animal * elem = buscar_elemento(v, &ant);

	// se for NULL, � porque n�o existe, ent�o retorna 0
	if(elem == NULL)
		return 0;

	// se chegou aqui, � porque o elemento existe e ser� removido

	// se o anterior for diferente de NULL, ent�o
	// faz o pr�ximo do anterior apontar para o pr�ximo
	// do elemento que ser� removido
	if(ant != NULL)
		ant->prox = elem->prox;

	// se o elemento a ser removido � igual ao corrente, ou seja,
	// � o �ltimo elemento, ent�o faz o corrente apontar para o anterior
	if(elem == corrente)
		corrente = ant;

	// se o elemento a ser removido � igual a cabeca, ou seja,
	// � o primeiro elemento, ent�o faz a cabeca apontar para o pr�ximo
	// do elemento a ser removido
	if(elem == cabeca)
		cabeca = elem->prox;

	// por �ltimo, d� um free no elemento a ser removido "elem" e coloca para NULL
	free(elem);
	elem = NULL;

	// retorna 1 indicando que removeu com sucesso
	return 1;
}

// fun��o que retorna o tamanho da lista
int tamanho_lista()
{
	if(lista_vazia())
		return 0;

	t_animal *aux = cabeca;
	int tam = 0;

	while(aux != NULL)
	{
		tam++;
		aux = aux->prox;
	}
	return tam;
}
