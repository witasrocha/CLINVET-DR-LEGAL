typedef struct sessoes{
	
		int v; 
		int k;
		char*data; 
		char*tipo; 
		char*sintomas; 
		char*diagnostico; 
		char*vacinas; 
		char*exames; 
		float preco; 
		struct sessoes *prox; // ponteiro para o pr�ximo elemento
	
	
} t_sessoes;


// vari�veis ponteiros globais que guardam refer�ncia
// para a cabe�a da lista e para o n� corrente
// cabeca da lista encadeada (come�a com NULL)
t_sessoes *head = NULL;
t_sessoes *chain = NULL;


// fun��o para criar uma lista
// recebe um valor inteiro e retorna um ponteiro do tipo t_sessoes
t_sessoes * create_list(int valor,int k, char*data, char*tipo, char*sintomas, char*diagnostico, char*vacinas, char*exames, float preco)
{
	
	// aloca espa�o em mem�ria
	t_sessoes * p = (t_sessoes*)malloc(sizeof(t_sessoes));    
	p->data = malloc(10); 
	p->tipo = malloc(255); 
	p->sintomas = malloc(255); 
	p->diagnostico = malloc(255); 
	p->vacinas = malloc(255); 
	p->exames = malloc(255)	; 

	// verifica se houve falha na aloca��o de mem�ria
	if(p == NULL)
	{
		printf("\nFalha ao alocar memoria\n");
		return NULL;
	}

	// se chegou aqui � porque foi feita a aloca��o com sucesso
	p->v = valor; // atribui o valor passado	
	p->k = k; 
    p->data=data; 
	p->tipo=tipo; 
	p->sintomas=sintomas; 
	p->diagnostico=diagnostico; 
	p->vacinas=vacinas; 
	p->exames=exames; 
	p->preco=preco; 
	p->prox = NULL; // o pr�ximo � NULL

	// faz a head e o chain apontar para p
	head = chain = p;
	// retorna o ponteiro alocado
	return p;
}


// fun��o que adiciona um elemento � lista
// recebe a head e o elemento a ser adicionado
// o elemento � inserido no FINAL da lista
t_sessoes* add_list(int v, int k,  char*data, char*tipo, char*sintomas, char*diagnostico, char*vacinas, char*exames, float preco)
{
	// verifica se a head � NULL (lista vazia), se for NULL,
	// ent�o retorna o retorno da fun��o criar_lista
	if(head == NULL)
	{
		return create_list(v, k, data, tipo, sintomas, diagnostico, vacinas, exames,preco);
	}

	// se chegou aqui � porque a lista N�O � vazia
	// aloca espa�o em mem�ria
	t_sessoes * p = (t_sessoes*)malloc(sizeof(t_sessoes));
    p->data = malloc(10); 
	p->tipo = malloc(255); 
	p->sintomas = malloc(255); 
	p->diagnostico = malloc(255); 
	p->vacinas = malloc(255); 
	p->exames = malloc(255); 	
	
	// verifica se houve falha na aloca��o de mem�ria
	if(p == NULL)
	{
		printf("\nFalha ao alocar memoria\n");
		return NULL;
	}

	// atribui valores
	p->v = v;
	p->k = k; 
    p->data=data; 
	p->tipo=tipo; 
	p->sintomas=sintomas; 
	p->diagnostico=diagnostico; 
	p->vacinas=vacinas; 
	p->exames=exames; 
	p->preco=preco;
	p->prox = NULL;

	// insere no FINAL da lista (obs.: tamb�m poderia ser no in�cio)
	// aqui ser� feita a inser��o no final,
	// a inser��o no in�cio fica como um desafio ;-)
	// para inser��o no final, fazemos com que o pr�ximo do n�
	// chain aponte para o "p"
	chain->prox = p;
	// o chain passar a ser o "p"
	chain = p;

	// retorna o ponteiro alocado
	return p;
}


// fun��o que imprime a lista
void print_list()
{
	// vari�vel ponteiro "aux" para percorrer a lista
	// inicialmente aponta para a "head"
	t_sessoes *aux = head;
    printf("\n %8s \n","XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX LISTAGEM DE SESSOES XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"  ); 
    printf("%10s\t%10s\t%10s\t%10s\t%10s\t%10s\t%10s\t%10s\t%10s\n", "ANIMAL", "SESSAO", "DATA","TIPO","SINTOMAS","DIAGNOSTICO","VACINAS","EXAME","PRECO"  ); 
	// enquanto "aux" for diferente de NULL
	while(aux != NULL)
	{
		// imprime o valor
		printf("%10d\t%10d\t%10s\t%10s\t%10s\t%10s\t%10s\t%10s\t%10f\n", aux->v,aux->k, aux->data, aux->tipo, aux->sintomas, aux->diagnostico, aux->vacinas, aux->exames, aux->preco);
		
		
		
		// aponta para o pr�ximo elemento da lista
		aux = aux->prox;
	}
}


// fun��o para verificar se a lista est� vazia
// retorna 1 se estiver vazia e 0 caso contr�rio
int empty_list()
{
	// se head for NULL, ent�o a lista est� vazia
	if(head == NULL)
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
t_sessoes * search_element(int v, t_sessoes **ant)
{
	// se a lista estiver vazia, ent�o n�o possui elementos,
	// portanto, retorna 0 indicando que N�O achou.
	if(lista_vazia() == 1)
		return NULL;

	// vari�vel "p" para percorrer a lista
	t_sessoes *p = head;
	// vari�vel "aux_ant" para guardar o anterior
	t_sessoes *aux_ant = NULL;
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
int remove_element(int v)
{
	// vari�vel que guarda a refer�ncia para o elemento anterior
	// do elemento que vai ser removido
	t_sessoes *ant = NULL;

	// busca pelo elemento a ser removido
	// passa a refer�ncia para o "ant" (ponteiro para ponteiro)
	// "elem" � o elemento que ser� removido
	t_sessoes * elem = search_element(v, &ant);

	// se for NULL, � porque n�o existe, ent�o retorna 0
	if(elem == NULL)
		return 0;

	// se chegou aqui, � porque o elemento existe e ser� removido

	// se o anterior for diferente de NULL, ent�o
	// faz o pr�ximo do anterior apontar para o pr�ximo
	// do elemento que ser� removido
	if(ant != NULL)
		ant->prox = elem->prox;

	// se o elemento a ser removido � igual ao chain, ou seja,
	// � o �ltimo elemento, ent�o faz o chain apontar para o anterior
	if(elem == chain)
		chain = ant;

	// se o elemento a ser removido � igual a head, ou seja,
	// � o primeiro elemento, ent�o faz a head apontar para o pr�ximo
	// do elemento a ser removido
	if(elem == head)
		head = elem->prox;

	// por �ltimo, d� um free no elemento a ser removido "elem" e coloca para NULL
	free(elem);
	elem = NULL;

	// retorna 1 indicando que removeu com sucesso
	return 1;
}

// fun��o que retorna o tamanho da lista
int size_list()
{
	if(empty_list())
		return 0;

	t_sessoes *aux = head;
	int tam = 0;

	while(aux != NULL)
	{
		tam++;
		aux = aux->prox;
	}
	return tam;
}
