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
		struct sessoes *prox; // ponteiro para o próximo elemento
	
	
} t_sessoes;


// variáveis ponteiros globais que guardam referência
// para a cabeça da lista e para o nó corrente
// cabeca da lista encadeada (começa com NULL)
t_sessoes *head = NULL;
t_sessoes *chain = NULL;


// função para criar uma lista
// recebe um valor inteiro e retorna um ponteiro do tipo t_sessoes
t_sessoes * create_list(int valor,int k, char*data, char*tipo, char*sintomas, char*diagnostico, char*vacinas, char*exames, float preco)
{
	
	// aloca espaço em memória
	t_sessoes * p = (t_sessoes*)malloc(sizeof(t_sessoes));    
	p->data = malloc(10); 
	p->tipo = malloc(255); 
	p->sintomas = malloc(255); 
	p->diagnostico = malloc(255); 
	p->vacinas = malloc(255); 
	p->exames = malloc(255)	; 

	// verifica se houve falha na alocação de memória
	if(p == NULL)
	{
		printf("\nFalha ao alocar memoria\n");
		return NULL;
	}

	// se chegou aqui é porque foi feita a alocação com sucesso
	p->v = valor; // atribui o valor passado	
	p->k = k; 
    p->data=data; 
	p->tipo=tipo; 
	p->sintomas=sintomas; 
	p->diagnostico=diagnostico; 
	p->vacinas=vacinas; 
	p->exames=exames; 
	p->preco=preco; 
	p->prox = NULL; // o próximo é NULL

	// faz a head e o chain apontar para p
	head = chain = p;
	// retorna o ponteiro alocado
	return p;
}


// função que adiciona um elemento à lista
// recebe a head e o elemento a ser adicionado
// o elemento é inserido no FINAL da lista
t_sessoes* add_list(int v, int k,  char*data, char*tipo, char*sintomas, char*diagnostico, char*vacinas, char*exames, float preco)
{
	// verifica se a head é NULL (lista vazia), se for NULL,
	// então retorna o retorno da função criar_lista
	if(head == NULL)
	{
		return create_list(v, k, data, tipo, sintomas, diagnostico, vacinas, exames,preco);
	}

	// se chegou aqui é porque a lista NÃO é vazia
	// aloca espaço em memória
	t_sessoes * p = (t_sessoes*)malloc(sizeof(t_sessoes));
    p->data = malloc(10); 
	p->tipo = malloc(255); 
	p->sintomas = malloc(255); 
	p->diagnostico = malloc(255); 
	p->vacinas = malloc(255); 
	p->exames = malloc(255); 	
	
	// verifica se houve falha na alocação de memória
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

	// insere no FINAL da lista (obs.: também poderia ser no início)
	// aqui será feita a inserção no final,
	// a inserção no início fica como um desafio ;-)
	// para inserção no final, fazemos com que o próximo do nó
	// chain aponte para o "p"
	chain->prox = p;
	// o chain passar a ser o "p"
	chain = p;

	// retorna o ponteiro alocado
	return p;
}


// função que imprime a lista
void print_list()
{
	// variável ponteiro "aux" para percorrer a lista
	// inicialmente aponta para a "head"
	t_sessoes *aux = head;
    printf("\n %8s \n","XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX LISTAGEM DE SESSOES XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"  ); 
    printf("%10s\t%10s\t%10s\t%10s\t%10s\t%10s\t%10s\t%10s\t%10s\n", "ANIMAL", "SESSAO", "DATA","TIPO","SINTOMAS","DIAGNOSTICO","VACINAS","EXAME","PRECO"  ); 
	// enquanto "aux" for diferente de NULL
	while(aux != NULL)
	{
		// imprime o valor
		printf("%10d\t%10d\t%10s\t%10s\t%10s\t%10s\t%10s\t%10s\t%10f\n", aux->v,aux->k, aux->data, aux->tipo, aux->sintomas, aux->diagnostico, aux->vacinas, aux->exames, aux->preco);
		
		
		
		// aponta para o próximo elemento da lista
		aux = aux->prox;
	}
}


// função para verificar se a lista está vazia
// retorna 1 se estiver vazia e 0 caso contrário
int empty_list()
{
	// se head for NULL, então a lista está vazia
	if(head == NULL)
		return 1;
	return 0;
}


// função para buscar um elemento na lista
// essa função recebe o valor a ser buscado e um ponteiro para ponteiro "ant"
// o "ant" servirá para guardarmos o anterior do elemento encontrado, pois
// iremos utilizar na remoção, assim fica mais otimizado para não ter que
// percorrer a lista novamente pois precisa-se do elemento anterior ao elemento
// que irá ser removido para ajustar corretamente a lista
// retorna o ponteiro para o elemento encontrado ou NULL se não encontrar
t_sessoes * search_element(int v, t_sessoes **ant)
{
	// se a lista estiver vazia, então não possui elementos,
	// portanto, retorna 0 indicando que NÃO achou.
	if(lista_vazia() == 1)
		return NULL;

	// variável "p" para percorrer a lista
	t_sessoes *p = head;
	// variável "aux_ant" para guardar o anterior
	t_sessoes *aux_ant = NULL;
	// flag "achou" que indica se achou o elemento
	int achou = 0;

	// percorre a lista
	while(p != NULL)
	{
		// se achou, então retorna 1
		if(p->v == v)
		{
			achou = 1;
			break;
		}
		// atualiza o "aux_ant"
		aux_ant = p;
		// aponta para o próximo
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

	// se chegou aqui, então não achou
	return NULL;
}

// função que remove um elemento da lista
// retorna 1 se conseguiu remover e 0 caso contrário
int remove_element(int v)
{
	// variável que guarda a referência para o elemento anterior
	// do elemento que vai ser removido
	t_sessoes *ant = NULL;

	// busca pelo elemento a ser removido
	// passa a referência para o "ant" (ponteiro para ponteiro)
	// "elem" é o elemento que será removido
	t_sessoes * elem = search_element(v, &ant);

	// se for NULL, é porque não existe, então retorna 0
	if(elem == NULL)
		return 0;

	// se chegou aqui, é porque o elemento existe e será removido

	// se o anterior for diferente de NULL, então
	// faz o próximo do anterior apontar para o próximo
	// do elemento que será removido
	if(ant != NULL)
		ant->prox = elem->prox;

	// se o elemento a ser removido é igual ao chain, ou seja,
	// é o último elemento, então faz o chain apontar para o anterior
	if(elem == chain)
		chain = ant;

	// se o elemento a ser removido é igual a head, ou seja,
	// é o primeiro elemento, então faz a head apontar para o próximo
	// do elemento a ser removido
	if(elem == head)
		head = elem->prox;

	// por último, dá um free no elemento a ser removido "elem" e coloca para NULL
	free(elem);
	elem = NULL;

	// retorna 1 indicando que removeu com sucesso
	return 1;
}

// função que retorna o tamanho da lista
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
