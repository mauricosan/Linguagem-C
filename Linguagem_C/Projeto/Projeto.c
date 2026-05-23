#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct
{
    char *name; //alocação dinâmica de nome
    char *cpf; //alocação dinâmica de cpf

    struct { /*preenchimento da data de nascimento*/
        int day;
        int month;
        int year;
    } dateOfBirth;

    char gender;

    char **emails; //alocação dinâmica de emails
    int totalEmails;

    char **phones; //alocação dinâmica de telefones
    int totalPhones;

} client;

typedef struct {
    int code;
    char *name;
    char *description;
    int durationHours;
    char period; // 'M', 'T', 'N'
    float price;
} course;


void titleBorder(char titulo[]) { //padranização do titulo
    int width = 30;
    int size = strlen(titulo);
    int spaces = (width - size) / 2;

    printf("|");
    for(int i=0;i<width;i++) printf("-");
    printf("|\n");

    printf("|");
    for(int i=0;i<spaces;i++) printf(" ");
    printf("%s", titulo);
    for(int i=0;i<width - size - spaces;i++) printf(" ");
    printf("|\n");

    printf("|");
    for(int i=0;i<width;i++) printf("-");
    printf("|\n");

    printf("\nEscolha uma opção:\n");
}

int readInteger() //verificação de leitura do tipo inteiro
{
    int num;

    while (1) {
        if (scanf("%d", &num) == 1) {
            while (getchar() != '\n');
            return num;
        } else {
            printf("\nOpção inválida! Digite um número válido.");
            while (getchar() != '\n');
        }
    }
}

void main_Menu()
{
    titleBorder("MENU PRINCIPAL");
    printf("\n[1] - Submenu de alunos");
    printf("\n[2] - Submenu de cursos");
    printf("\n[3] - Submenu de matrícula");
    printf("\n[4] - Submenu de relatórios");
    printf("\n[0] - Sair");
}

void studentSubmenu()
{
    titleBorder("MENU DE ALUNOS");
    printf("\n[1] - Cadastrar aluno");
    printf("\n[2] - Listar alunos");
    printf("\n[3] - Listar aluno por CPF");
    printf("\n[4] - Atualizar aluno");
    printf("\n[5] - Remover aluno");
    printf("\n[6] - Adicionar email");
    printf("\n[7] - Adicionar telefone");
    printf("\n[0] - Voltar");
}

void courseSubmenu()
{
    titleBorder("MENU DE CURSOS");
    printf("\n[1] - Cadastrar curso");
    printf("\n[2] - Listar todos os cursos");
    printf("\n[3] - Buscar curso por código");
    printf("\n[4] - Atualizar curso");
    printf("\n[5] - Excluir curso");
    printf("\n[0] - Voltar");
}

void enrollmentSubmenu()
{
    titleBorder("MENU DE MATRÍCULAS");
    printf("\n[1] - Realizar matrícula");
    printf("\n[2] - Listar todas as matrículas");
    printf("\n[3] - Buscar matricula (CPF + Codigo do curso)");
    printf("\n[4] - Atualizar matrícula");
    printf("\n[5] - Cancelar matrícula");
    printf("\n[0] - Voltar");
}

void reportsSubmenu()
{
    titleBorder("MENU DE RELATORIOS");
    printf("\n[1] - Listar alunos por curso");
    printf("\n[2] - Listar cursos por periodo");
    printf("\n[3] - Listar cursos de um aluno");
    printf("\n[0] - Voltar");
}

//CLIENTES
int clientRegistration(
    client *c,
    int *totalClients,
    char *name,
    char *cpf,
    int day, int month, int year,
    char gender,
    char *email,
    char *phone )
{
    // Verifica CPF
    for (int i = 0; i < *totalClients; i++) //percorre todos os clientes
    {
        if (strcmp(c[i].cpf, cpf) == 0) //veirifca se o cpf já existe
        {
            return 0; //para a execução
        }
    }

    client *newClient = &c[*totalClients]; /* se já existirem 2 clientes, a variável "newClient" apontará para a próxima posição livre da struct */

    // name
    newClient->name = malloc(strlen(name) + 1); // alocação dinâmica, reservando espaço para o "Ω /n"
    strcpy(newClient->name, name);

    // cpf
    newClient->cpf = malloc(strlen(cpf) + 1);
    strcpy(newClient->cpf, cpf);

    // date
    newClient->dateOfBirth.day = day; //newClient está acessando o "day" de "dayOfBirth"
    newClient->dateOfBirth.month = month;
    newClient->dateOfBirth.year = year;

    // gender
    newClient->gender = gender;

    // email
    newClient->totalEmails = 1;
    newClient->emails = malloc(sizeof(char*)); //criando um espaço na memória
    newClient->emails[0] = malloc(strlen(email) + 1); //aloc dinâmica
    strcpy(newClient->emails[0], email); // colocando no primeiro índice

    // phone
    newClient->totalPhones = 1;
    newClient->phones = malloc(sizeof(char*));
    newClient->phones[0] = malloc(strlen(phone) + 1);
    strcpy(newClient->phones[0], phone);

    (*totalClients)++;

    return 1;
}

int validateCPF(char *cpf)
{
    //tamanho diferente de 11 = erro
    if (strlen(cpf) != 11) return 0;

    //só números
    for (int i = 0; i < 11; i++)
    {
        if (cpf[i] < '0' || cpf[i] > '9') //percorre todos os índices do cpf
        {
            return 0;
        }
    }

    // evita cpf com num unico
    int iguais = 1;
    for (int i = 1; i < 11; i++)
    {
        if (cpf[i] != cpf[0])
        {
            iguais = 0;
            break;
        }
    }
    if (iguais) return 0;

    return 1;
}

int validateEmail(char *email) {
    int temArroba = 0;
    int temPontoDepois = 0;
    int posArroba = -1;

    int tamanho = strlen(email);

    if (tamanho < 5) return 0; //mínimo básico 6

    for (int i = 0; i < tamanho; i++)
    {
        // não pode ter espaço
        if (email[i] == ' ') return 0;

        //verifica @
        if (email[i] == '@')
        {
            if (temArroba) return 0; // mais de um @
            temArroba = 1;
            posArroba = i;
        }

        //verifica ponto depois do @
        if (email[i] == '.' && temArroba && i > posArroba + 1)
        {
            temPontoDepois = 1;
        }
    }

    //@ não pode ser primeiro ou último
    if (posArroba <= 0 || posArroba >= tamanho - 1) return 0;

    //precisa ter ponto depois do @
    if (!temPontoDepois) return 0;

    //não pode terminar com ponto
    if (email[tamanho - 1] == '.') return 0;

    return 1;
}

int validatePhone(char *phone) {

    int size = strlen(phone);

    if (size != 10 && size != 11) return 0; //tamanho do telefone deve ser 10 ou 11

    for (int i = 0; i < size; i++) {
        if (phone[i] < '0' || phone[i] > '9') { //percore o todos os índices do telefone
            return 0;
        }
    }

    return 1;
}

int validateData(int day, int month, int year) {

    if (year < 1909 || year > 2026) return 0; //deve estar entre 1909 e 2026
    if (month < 1 || month > 12) return 0; //de janeiro até dezembro
    if (day < 1 || day > 31) return 0; //o mês tem, 31 dias, exceto alguns

    // meses com 30 dias
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return 0;

    // fevereiro ate 28
    if (month == 2 && day > 28)
        return 0;

    return 1;
}

void registerCustomer(client **clients, int *totalClients) { //função de cadastrar cliente

    char name[100];
    char cpf[20];
    char email[100];
    char phone[20];
    int day, month, year;
    char gender;

    printf("\nNome: ");
    scanf(" %[^\n]", name);

    do {
        printf("CPF: ");
        scanf("%s", cpf);

        if (!validateCPF(cpf))
        {
            printf("CPF inválido!\n");
        }

    } while (!validateCPF(cpf));

    do {
        printf("Dia: ");
        day = readInteger();

        printf("Mês: ");
        month = readInteger();

        printf("Ano: ");
        year = readInteger();

        if (!validateData(day, month, year))
        {
            printf("Data inválida!\n");
        }

    } while (!validateData(day, month, year));

    do {
        printf("Gênero (M/F): ");
        scanf(" %c", &gender);

        if (gender != 'M' && gender != 'F' &&
            gender != 'm' && gender != 'f')
            {
            printf("Valor inválido!.\n");
        }

    } while (gender != 'M' && gender != 'F' && gender != 'm' && gender != 'f');

    if (gender == 'm') gender = 'M';
    if (gender == 'f') gender = 'F';

    do {
        printf("Email: ");
        scanf("%s", email);

        if (!validateEmail(email)) {
            printf("Email inválido! Ex: nome@email.com\n");
        }

    } while (!validateEmail(email));

    do {
        printf("Telefone: ");
        scanf("%s", phone);

        if (!validatePhone(phone)) {
            printf("Telefone inválido! Digite apenas números, 10 ou 11 dígitos.\n");
        }

    } while (!validatePhone(phone));

    client *temp = realloc(*clients, (*totalClients + 1) * sizeof(client));

    if (temp == NULL) {
        printf("Erro de memória!\n");
        return;
    }

    *clients = temp;

    int result = clientRegistration(
        *clients,
        totalClients,
        name,
        cpf,
        day, month, year,
        gender,
        email,
        phone
    );

    if (result == 1) {
        printf("\nCadastrado com sucesso!\n");
    } else {
        printf("\nCPF já existe!\n");
        *clients = realloc(*clients, (*totalClients) * sizeof(client));
    }
}

int addEmail(client *clients, int totalClients, char *cpf)
{
    for (int i = 0; i < totalClients; i++)
    {
        if (strcmp(clients[i].cpf, cpf) == 0)
        {
            char novoEmail[100];

            do {
                printf("Novo email: ");
                scanf("%s", novoEmail);

                if (!validateEmail(novoEmail))
                    printf("Email inválido! Ex: nome@email.com\n");

            } while (!validateEmail(novoEmail));

            // realoca o vetor de emails com +1 posição
            char **temp = realloc(clients[i].emails, (clients[i].totalEmails + 1) * sizeof(char *));

            if (temp == NULL) {
                printf("Erro de memória!\n");
                return 0;
            }

            clients[i].emails = temp;

            // aloca e copia o novo email na última posição
            clients[i].emails[clients[i].totalEmails] = malloc(strlen(novoEmail) + 1);
            strcpy(clients[i].emails[clients[i].totalEmails], novoEmail);

            clients[i].totalEmails++;

            printf("Email adicionado com sucesso!\n");
            return 1;
        }
    }

    printf("Cliente não encontrado!\n");
    return 0;
}

int addPhone(client *clients, int totalClients, char *cpf)
{
    for (int i = 0; i < totalClients; i++)
    {
        if (strcmp(clients[i].cpf, cpf) == 0)
        {
            char novoTelefone[20];

            do {
                printf("Novo telefone: ");
                scanf("%s", novoTelefone);

                if (!validatePhone(novoTelefone))
                    printf("Telefone inválido! Digite apenas números, 10 ou 11 dígitos.\n");

            } while (!validatePhone(novoTelefone));

            // realoca o vetor de telefones com +1 posição
            char **temp = realloc(clients[i].phones, (clients[i].totalPhones + 1) * sizeof(char *));

            if (temp == NULL) {
                printf("Erro de memória!\n");
                return 0;
            }

            clients[i].phones = temp;

            // aloca e copia o novo telefone na última posição
            clients[i].phones[clients[i].totalPhones] = malloc(strlen(novoTelefone) + 1);
            strcpy(clients[i].phones[clients[i].totalPhones], novoTelefone);

            clients[i].totalPhones++;

            printf("Telefone adicionado com sucesso!\n");
            return 1;
        }
    }

    printf("Cliente não encontrado!\n");
    return 0;
}

int listStudent (client *clients, int totalClients)
{
    int i, j;

    if (totalClients == 0)
    {
        return 0;
    }

    for (i = 0; i < totalClients; i++)
    {
        printf("\n----- %dº Cliente -----\n", i+1);
        printf("Nome: %s\n", clients[i].name);
        printf("CPF: %s\n", clients[i].cpf);

        printf("Data de Nascimento: %d/%d/%d\n",
            clients[i].dateOfBirth.day,
            clients[i].dateOfBirth.month,
            clients[i].dateOfBirth.year);

        printf("Gênero: %c\n", clients[i].gender);

        printf("Emails:\n");
        for (j = 0; j < clients[i].totalEmails; j++)
        {
            printf(" - %s\n", clients[i].emails[j]);
        }

        printf("Telefones:\n");
        for (j = 0; j < clients[i].totalPhones; j++)
        {
            printf(" - %s\n", clients[i].phones[j]);
        }
    }

    return 1;
}

int findStudentByCPF(client *clients, int totalClients, char *cpf)
{
    for (int i = 0; i < totalClients; i++)
    {
        if (strcmp(clients[i].cpf, cpf) == 0)
        {
            printf("\n----- Cliente encontrado -----\n");
            printf("Nome: %s\n", clients[i].name);
            printf("CPF: %s\n", clients[i].cpf);

            printf("Data de Nascimento: %d/%d/%d\n",
                clients[i].dateOfBirth.day,
                clients[i].dateOfBirth.month,
                clients[i].dateOfBirth.year);

            printf("Gênero: %c\n", clients[i].gender);

            printf("Emails:\n");
            for (int j = 0; j < clients[i].totalEmails; j++)
            {
                printf(" - %s\n", clients[i].emails[j]);
            }

            printf("Telefones:\n");
            for (int j = 0; j < clients[i].totalPhones; j++)
            {
                printf(" - %s\n", clients[i].phones[j]);
            }
            return 1;
        }
    }

    return 0;
}

int updateStudent(client *clients, char *cpf, int totalClients)
{
    int i;

    //percorre todos os clientes
    for (i = 0; i < totalClients; i++)
    {
        //compara o cpf digitado
        if (strcmp(clients[i].cpf, cpf) == 0)
        {
            int option = -1; //controla o menu, começa em -1 para ser diferente e entrar no loop
            char temp[100]; //buffer temporário, evita erro de memória

            printf("Cliente encontrado:\n");

            //repete até o usuario digitar 0
            while (option != 0)
            {
                printf("\nO que deseja atualizar?\n");
                printf("1 - Nome\n");
                printf("2 - Data de Nascimento\n");
                printf("3 - Gênero\n");
                printf("4 - Emails\n");
                printf("5 - Telefones\n");
                printf("6 - Atualizar Tudo\n");
                printf("0 - Sair\n");
                printf("Escolha: ");
                scanf("%d", &option);
                getchar(); //limpa o enter do buffer

                switch (option)
                {
                case 1:
                    printf("Novo nome: ");
                    fgets(temp, sizeof(temp), stdin); //lê nome com espaço até 99 caracteres
                    temp[strcspn(temp, "\n")] = '\0'; //remove o /n

                    char *newName = realloc(clients[i].name, strlen(temp) + 1); // realoca memória para o nome com o tamanho exato do novo valor

                    if (newName != NULL)  //se não estiver apontando para nenhum lugar
                    {
                        clients[i].name = newName; //copia o novo nome para a struct
                        strcpy(clients[i].name, temp);
                    }
                    else {
                        printf("Erro ao realocar nome!\n");
                    }

                    printf("Nome atualizado com sucesso!\n");
                    break;

                case 2:
                    do {
                        printf("Nova data de nascimento: ");
                        scanf("%d %d %d",
                            &clients[i].dateOfBirth.day,
                            &clients[i].dateOfBirth.month,
                            &clients[i].dateOfBirth.year);

                        if (!validateData(
                            clients[i].dateOfBirth.day,
                            clients[i].dateOfBirth.month,
                            clients[i].dateOfBirth.year))
                        {
                            printf("Data inválida!\n");
                        }

                    } while (!validateData(
                        clients[i].dateOfBirth.day,
                        clients[i].dateOfBirth.month,
                        clients[i].dateOfBirth.year)); //repete enquanto não cumprir os requisitos

                    getchar(); // limpa buffer
                    printf("Data atualizada com sucesso!\n");
                    break;

                case 3:
                    do {
                        printf("Novo gênero (M/F): ");
                        scanf(" %c", &clients[i].gender);

                        if (clients[i].gender != 'M' && clients[i].gender != 'F' &&
                            clients[i].gender != 'm' && clients[i].gender != 'f')
                        {
                            printf("Valor inválido!\n");
                        }

                    } while (clients[i].gender != 'M' && clients[i].gender != 'F' &&
                            clients[i].gender != 'm' && clients[i].gender != 'f'); //repete enquanto não cumprir os requisitos

                    //padroniza para maiúsculo
                    if (clients[i].gender == 'm') clients[i].gender = 'M';
                    if (clients[i].gender == 'f') clients[i].gender = 'F';

                    printf("Gênero atualizado com sucesso!\n");
                    break;

                case 4:
                    //libera emails antigos antes de recriar
                    for (int j = 0; j < clients[i].totalEmails; j++) {
                        free(clients[i].emails[j]);
                    }
                    free(clients[i].emails); //libera o vetor antigo

                    // pergunta quantos emails o cliente terá agora
                    printf("Informe quantos e-mails deseja adicionar: ");
                    scanf("%d", &clients[i].totalEmails);
                    getchar(); //limpa o enter do buffer

                    // aloca novo vetor de emails
                    char **emailsTemp = malloc(clients[i].totalEmails * sizeof(char*));

                    if (emailsTemp != NULL)  { //se não estiver apontando para nenhum lugar
                        clients[i].emails = emailsTemp;
                    } else {
                        printf("Erro ao alocar emails!\n");
                        break;
                    }

                    //percorre cada posição do vetor de emails e preenche
                    for (int j = 0; j < clients[i].totalEmails; j++)
                    {
                        printf("Email %d: ", j+1);

                        //lê o email digitado
                        fgets(temp, sizeof(temp), stdin);

                        temp[strcspn(temp, "\n")] = '\0';

                        // aloca memória exata para esse email
                        clients[i].emails[j] = malloc(strlen(temp) + 1);

                        if (clients[i].emails[j] == NULL) {
                            printf("Erro ao alocar email!\n");
                            break;
                        }

                        // copia o conteúdo do temp para o vetor de emails
                        strcpy(clients[i].emails[j], temp);
                    }

                    // mensagem de sucesso
                    printf("Emails atualizados!\n");
                    break;

                case 5:
                    // libera telefones antigos antes de recriar
                    for (int j = 0; j < clients[i].totalPhones; j++) {
                        free(clients[i].phones[j]);
                    }
                    free(clients[i].phones); // libera o vetor antigo

                    printf("Quantos telefones? ");
                    scanf("%d", &clients[i].totalPhones);
                    getchar();

                    //aloca novo vetor de telefones
                    char **phonesTemp = malloc(clients[i].totalPhones * sizeof(char*)); // nova alocação segura

                    if (phonesTemp != NULL) { //se não estiver apontando para nenhum lugar
                        clients[i].phones = phonesTemp;
                    } else {
                        printf("Erro ao alocar telefones!\n");
                        break;
                    }

                    for (int j = 0; j < clients[i].totalPhones; j++)
                    {
                        printf("Telefone %d: ", j+1);
                        fgets(temp, sizeof(temp), stdin);
                        temp[strcspn(temp, "\n")] = '\0';

                        clients[i].phones[j] = malloc(strlen(temp) + 1);
                        strcpy(clients[i].phones[j], temp);
                    }

                    printf("Telefones atualizados!\n");
                    break;

                case 6: {
                        char tempName[100];

                        int c;
                        while ((c = getchar()) != '\n' && c != EOF);//limpa o buffer antes de ler a string

                        printf("Novo nome: ");
                        fgets(tempName, sizeof(tempName), stdin);
                        tempName[strcspn(tempName, "\n")] = '\0';

                        free(clients[i].name);
                        clients[i].name = malloc(strlen(tempName) + 1);
                        strcpy(clients[i].name, tempName);

                        do {
                            printf("Nova data (dd mm aaaa): ");
                            scanf("%d %d %d",
                                &clients[i].dateOfBirth.day,
                                &clients[i].dateOfBirth.month,
                                &clients[i].dateOfBirth.year);

                            if (!validateData(
                                clients[i].dateOfBirth.day,
                                clients[i].dateOfBirth.month,
                                clients[i].dateOfBirth.year))
                            {
                                printf("Data inválida!\n");
                            }

                        } while (!validateData(
                            clients[i].dateOfBirth.day,
                            clients[i].dateOfBirth.month,
                            clients[i].dateOfBirth.year));

                        do {
                            printf("Novo gênero (M/F): ");
                            scanf(" %c", &clients[i].gender);

                            if (clients[i].gender != 'M' && clients[i].gender != 'F' &&
                                clients[i].gender != 'm' && clients[i].gender != 'f')
                            {
                                printf("Valor inválido!\n");
                            }

                        } while (clients[i].gender != 'M' && clients[i].gender != 'F' &&
                                clients[i].gender != 'm' && clients[i].gender != 'f');

                        if (clients[i].gender == 'm') clients[i].gender = 'M';
                        if (clients[i].gender == 'f') clients[i].gender = 'F';

                        printf("Quantos emails? ");
                        scanf("%d", &clients[i].totalEmails);
                        getchar();

                        // libera emails antigos antes de recriar
                        for (int j = 0; j < clients[i].totalEmails; j++) {
                            free(clients[i].emails[j]);
                        }
                        free(clients[i].emails);

                        // aloca novo vetor de emails
                        char **emailsTemp2 = malloc(clients[i].totalEmails * sizeof(char*)); //nova alocação

                        if (emailsTemp2 != NULL) {
                            clients[i].emails = emailsTemp2;
                        }
                        else {
                            printf("Erro ao alocar emails!\n");
                            break;
                        }

                        for (int j = 0; j < clients[i].totalEmails; j++) {
                            printf("Email %d: ", j + 1);
                            fgets(tempName, sizeof(tempName), stdin);
                            tempName[strcspn(tempName, "\n")] = '\0';

                            clients[i].emails[j] = malloc(strlen(tempName) + 1);
                            strcpy(clients[i].emails[j], tempName);
                        }

                        printf("Quantos telefones? ");
                        scanf("%d", &clients[i].totalPhones);
                        getchar();

                        //libera telefones antigos antes de recriar
                        for (int j = 0; j < clients[i].totalPhones; j++) {
                            free(clients[i].phones[j]);
                        }
                        free(clients[i].phones);

                        //aloca novo vetor de telefones
                        char **phonesTemp2 = malloc(clients[i].totalPhones * sizeof(char*)); // nova alocação

                        if (phonesTemp2 != NULL) { //se não estiver apontando para nenhum lugar
                            clients[i].phones = phonesTemp2;
                        } else {
                            printf("Erro ao alocar telefones!\n");
                            break;
                        }

                        for (int j = 0; j < clients[i].totalPhones; j++) {
                            printf("Telefone %d: ", j + 1);
                            fgets(tempName, sizeof(tempName), stdin);
                            tempName[strcspn(tempName, "\n")] = '\0';

                            clients[i].phones[j] = malloc(strlen(tempName) + 1);
                            strcpy(clients[i].phones[j], tempName);
                        }

                        printf("Atualização completa realizada!\n");
                        break;
                    }
                case 0:
                    printf("Saindo...\n");
                    break;

                default:
                    printf("Opção inválida!\n");
                    break;
                }
            }
            return 1;
        }
    }

    return 0;
}

void removeStudent(client **clients, int *totalClients, char *cpf)
{
    for (int i = 0; i < *totalClients; i++)
    {
        if (strcmp((*clients)[i].cpf, cpf) == 0)
        {
            printf("Cliente encontrado: %s\n", (*clients)[i].name);
            printf("Removendo cliente...\n");

            free((*clients)[i].name);
            free((*clients)[i].cpf);

            for (int j = 0; j < (*clients)[i].totalEmails; j++) //percorre todos os emails do cliente
            {
                free((*clients)[i].emails[j]); //libera cada email
            }
            free((*clients)[i].emails); //libera o vetor de emails

            for (int j = 0; j < (*clients)[i].totalPhones; j++)
            {
                free((*clients)[i].phones[j]);
            }
            free((*clients)[i].phones);

            //move os clientes restantes para preencher
            for (int k = i; k < *totalClients - 1; k++)
            {
                (*clients)[k] = (*clients)[k + 1]; 
            }

            //reduz o total de clientes e realoca a memória
            (*totalClients)--;
            client *temp = realloc(*clients, (*totalClients) * sizeof(client)); //realoca a memória para o novo tamanho

            if (temp != NULL || *totalClients == 0)
            {
                *clients = temp; //att o ponteiro para o novo endereço de memória
                printf("Cliente removido com sucesso!\n");
            }
            else
            {
                printf("Erro ao realocar memória após remoção!\n");
            }
            return;
        }
    }
    printf("Cliente não encontrado!\n");
}

//CURSOS

int validateCourseCode(int code) {
    if (code <= 0) return 0; // código deve ser positivo
    else {
        return 1;
    }
}

int validateCourseName(char *name) {
    if (strlen(name) == 0)
    {
        return 0;
    }
    else {
        return 1;
    }
}

int validateCourseDescription(char *description) {
    if (strlen(description) == 0)
    {
        return 0;
    }
    else {
        return 1;
    }
}

int validateCourseDuration(int duration) {
    if (duration <= 0)
    {
        return 0;
    }
    else {
        return 1;
    }
}

int validateCoursePeriod(char period) {

    if (period == 'm' || period == 'M' || period == 't' || period == 'T' || period == 'n' || period == 'N')
    {
        return 1;
    }
    else {
        return 0;
    }
}

int validateCoursePrice(float price) {
    if (price < 0)
    {
        return 0;
    }
    else {
        return 1;
    }
}

int courseRegistration(
    course *c,
    int *totalCourses,
    int code,
    char *name,
    char *description,
    int durationHours,
    char period,
    float price)
{
    // Verifica código
    for (int i = 0; i < *totalCourses; i++) //percorre todos os cursos
    {
        if (c[i].code == code) //verifica se o código já existe
        {
            return 0;
        }
    }

    course *newCourse = &c[*totalCourses]; //se já existirem cursos, "newCourse" apontará para a próxima posição livre

    newCourse->code = code;

    newCourse->name = malloc(strlen(name) + 1);
    strcpy(newCourse->name, name);

    newCourse->description = malloc(strlen(description) + 1);
    strcpy(newCourse->description, description);

    newCourse->durationHours = durationHours;
    newCourse->period = period;
    newCourse->price = price;

    (*totalCourses)++;

    return 1;
}

void registerCourse(course **courses, int *totalCourses) {
    int code;
    char name[100];
    char description[255];
    int durationHours;
    char period;
    float price;

    do {
        printf("\nCódigo do curso: ");
        code = readInteger();
        if (!validateCourseCode(code)) printf("Código inválido!\n");
    } while (!validateCourseCode(code));

    printf("Nome do curso: ");
    scanf("%s \n", name);

    printf("Descrição do curso: ");
    scanf("%s", description);

    do {
        printf("Duração (horas): ");
        durationHours = readInteger();
        if (!validateCourseDuration(durationHours)) printf("Duração inválida!\n");
    } while (!validateCourseDuration(durationHours));

    do {
        printf("Período (M/T/N): ");
        scanf(" %c", &period);
        if (!validateCoursePeriod(period)) printf("Período inválido! Use M, T ou N.\n");
    } while (!validateCoursePeriod(period));

    //padroniza para maiúsculo
    if (period == 'm') period = 'M';
    if (period == 't') period = 'T';
    if (period == 'n') period = 'N';

    do {
        printf("Preço: ");
        scanf("%f", &price);
        if (!validateCoursePrice(price)) printf("Preço inválido!\n");
    } while (!validateCoursePrice(price));

    course *temp = realloc(*courses, (*totalCourses + 1) * sizeof(course));//realoca a memória para o novo curso

    if (temp == NULL) {
        printf("Erro de memória!\n");
        return;
    }

    *courses = temp;

    int result = courseRegistration(
        *courses,
        totalCourses,
        code,
        name,
        description,
        durationHours,
        period,
        price
    );

    if (result == 1) {
        printf("\nCurso cadastrado com sucesso!\n");
    } else {
        printf("\nCódigo de curso já existe!\n");
        *courses = realloc(*courses, (*totalCourses) * sizeof(course));
    }
}

void listCourses(course *courses, int totalCourses) {
    if (totalCourses == 0) {
        printf("Nenhum curso encontrado!\n");
        return;
    }

    for (int i = 0; i < totalCourses; i++) {
        printf("\n----- %dº Curso -----\n", i + 1);
        printf("Código: %d\n", courses[i].code);
        printf("Nome: %s\n", courses[i].name);
        printf("Descrição: %s\n", courses[i].description);
        printf("Duração (horas): %d\n", courses[i].durationHours);
        printf("Período: %c\n", courses[i].period);
        printf("Preço: R$ %.2f\n", courses[i].price);
    }
}

int findCourseByCode(course *courses, int totalCourses, int code)
{
    for (int i = 0; i < totalCourses; i++)
    {
        if (courses[i].code == code)
        {
            printf("\n----- Curso encontrado -----\n");
            printf("Código: %d\n", courses[i].code);
            printf("Nome: %s\n", courses[i].name);
            printf("Descrição: %s\n", courses[i].description);
            printf("Duração: %d horas\n", courses[i].durationHours);
            printf("Período: %c\n", courses[i].period);
            printf("Preço: R$ %.2f\n", courses[i].price);
            return 1;
        }
    }
    return 0;
}

int updateCourse(course *courses, int totalCourses, int code)
{
    for (int i = 0; i < totalCourses; i++)
    {
        if (courses[i].code == code)
        {
            int option = -1; //controla o menu, começa em -1 para ser diferente e entrar no loop
            printf("Curso encontrado!\n");

            //repete até o usuario digitar 0
            while (option != 0)
            {
                printf("\nO que deseja atualizar?\n");
                printf("1 - Nome\n");
                printf("2 - Descrição\n");
                printf("3 - Duração\n");
                printf("4 - Período\n");
                printf("5 - Preço\n");
                printf("0 - Sair\n");
                printf("Escolha: ");
                option = readInteger();

                switch (option)
                {
                case 1: {
                    char temp[100];
                    printf("Novo nome: ");
                    scanf(" %[^\n]", temp);

                    char *newName = realloc(courses[i].name, strlen(temp) + 1); // realoca memória para o nome

                    if (newName != NULL) { //se não estiver apontando para nenhum lugar
                        courses[i].name = newName;
                        strcpy(courses[i].name, temp);
                    }
                    printf("Nome atualizado!\n");
                    break;
                }

                case 2: {
                    char temp[255];
                    printf("Nova descrição: ");
                    scanf(" %[^\n]", temp);

                    char *newDesc = realloc(courses[i].description, strlen(temp) + 1); // realoca memória para a descrição

                    if (newDesc != NULL) { //se não estiver apontando para nenhum lugar
                        courses[i].description = newDesc;
                        strcpy(courses[i].description, temp);
                    }
                    printf("Descrição atualizada!\n");
                    break;
                }

                case 3:
                    do {
                        printf("Nova duração (horas): ");
                        courses[i].durationHours = readInteger();
                        if (!validateCourseDuration(courses[i].durationHours))
                            printf("Duração inválida!\n");
                    } while (!validateCourseDuration(courses[i].durationHours)); //repete enquanto não cumprir os requisitos

                    printf("Duração atualizada!\n");
                    break;

                case 4:
                    do {
                        printf("Novo período (M/T/N): ");
                        scanf(" %c", &courses[i].period);
                        if (!validateCoursePeriod(courses[i].period))
                            printf("Período inválido!\n");
                    } while (!validateCoursePeriod(courses[i].period)); //repete enquanto não cumprir os requisitos

                    //padroniza para maiúsculo
                    if (courses[i].period == 'm') courses[i].period = 'M';
                    if (courses[i].period == 't') courses[i].period = 'T';
                    if (courses[i].period == 'n') courses[i].period = 'N';

                    printf("Período atualizado!\n");
                    break;

                case 5:
                    do {
                        printf("Novo preço: ");
                        scanf("%f", &courses[i].price);
                        if (!validateCoursePrice(courses[i].price))
                            printf("Preço inválido!\n");
                    } while (!validateCoursePrice(courses[i].price)); //repete enquanto não cumprir os requisitos

                    printf("Preço atualizado!\n");
                    break;

                case 0:
                    printf("Saindo...\n");
                    break;

                default:
                    printf("Opção inválida!\n");
                    break;
                }
            }
            return 1;
        }
    }
    return 0;
}

void deleteCourse(course **courses, int *totalCourses, int code)
{
    for (int i = 0; i < *totalCourses; i++)
    {
        if ((*courses)[i].code == code)
        {
            // Libera memória do curso
            free((*courses)[i].name);
            free((*courses)[i].description);

            //move os cursos restantes para preencher a lacuna
            for (int k = i; k < *totalCourses - 1; k++)
            {
                (*courses)[k] = (*courses)[k + 1]; //sobrescreve o curso a ser removido com o próximo
            }

            //reduz o total de cursos e realoca a memória
            (*totalCourses)--;
            course *temp = realloc(*courses, (*totalCourses) * sizeof(course)); //realoca a memória para o novo tamanho

            if (temp != NULL || *totalCourses == 0) // Verifica se a realocação deu certo ou se não tem mais cursos
            {
                *courses = temp; //att o ponteiro para o novo endereço de memória
                printf("Curso removido com sucesso!\n");
            }
            else
            {
                printf("Erro ao realocar memória!\n");
            }
            return;
        }
    }
    printf("Curso não encontrado!\n");
}

//MATRÍCULAS

//ARQUIVOS

//RELATÓRIOS




int main()
{
    setlocale(LC_ALL, "Portuguese");

    int mainMenu = -1;
    client *clients = NULL;
    int totalClients = 0;

    course *courses = NULL;  
    int totalCourses = 0;

    do
    {
        main_Menu();
        printf("\n");
        mainMenu = readInteger();

        switch(mainMenu)
        {
        case 1: {
            int student;

            do {
                studentSubmenu();
                printf("\n");
                student = readInteger();

                switch(student)
                {
                case 0:
                    break;

                case 1: {
                    registerCustomer(&clients, &totalClients);
                    break;
                }

                case 2: {
                    if(listStudent(clients, totalClients) != 1)
                    {
                        printf("\nNenhum cliente encontrado!\n");
                    }
                    break;
                }

                case 3: {
                    char cpf[20];

                    printf("Digite o CPF: ");
                    scanf("%s", cpf);

                    if (findStudentByCPF(clients, totalClients, cpf) == 1)
                    {
                        printf("\nBusca finalizada!\n");
                    }
                    else
                    {
                        printf("\nCliente não encontrado!\n");
                    }
                    break;
                }

                case 4: {
                    char cpf[20];

                    printf("Digite o CPF do cliente: ");
                    scanf("%s", cpf);

                    if (updateStudent(clients, cpf, totalClients) == 1)
                    {
                        printf("Atualização finalizada!\n");
                    }
                    else
                    {
                        printf("Cliente não encontrado!\n");
                    }
                    break;
                }

                case 5: {
                    char cpf[20];

                    printf("Digite o CPF do cliente: ");
                    scanf("%s", cpf);

                    removeStudent(&clients, &totalClients, cpf);
                    break;
                }

                case 6: {
                    char cpf[20];

                    printf("Digite o CPF do cliente: ");
                    scanf("%s", cpf);

                    if (addEmail(clients, totalClients, cpf) == 1)
                    {
                        printf("Email adicionado!\n");
                    }
                    else
                    {
                        printf("Cliente não encontrado!\n");
                    }
                    break;
                }

                case 7: {
                    char cpf[20];

                    printf("Digite o CPF do cliente: ");
                    scanf("%s", cpf);

                    if (addPhone(clients, totalClients, cpf) == 1)
                    {
                        printf("Telefone adicionado!\n");
                    }
                    else
                    {
                        printf("Cliente não encontrado!\n");
                    }
                    break;
                }

                default:
                    printf("\nOpção inválida\n");
                    break;

                } 

            } while (student != 0);

            break;
        }

        case 2: {
            int courseOption; 

            do {
                courseSubmenu();
                printf("\n");
                courseOption = readInteger();

                switch (courseOption)
                {
                case 0:
                    break;

                case 1:
                    registerCourse(&courses, &totalCourses);
                    break;

                case 2:
                    listCourses(courses, totalCourses);
                    break;

                case 3: {
                    int code;
                    printf("Digite o código do curso: ");
                    code = readInteger();
                    if (findCourseByCode(courses, totalCourses, code) != 1)
                        printf("\nCurso não encontrado!\n");
                    break;
                }

                case 4: {
                    int code;
                    printf("Digite o código do curso: ");
                    code = readInteger();
                    if (updateCourse(courses, totalCourses, code) != 1)
                        printf("\nCurso não encontrado!\n");
                    break;
                }

                case 5: {
                    int code;
                    printf("Digite o código do curso: ");
                    code = readInteger();
                    deleteCourse(&courses, &totalCourses, code);
                    break;
                }

                default:
                    printf("\nOpção inválida\n");
                    break;

                }

            } while (courseOption != 0);

            break;
        }

        case 3: {
            int enrollment;

            do {
                enrollmentSubmenu();
                printf("\n");
                enrollment = readInteger();

                switch (enrollment)
                {
                case 0:
                    break;
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;

                default:
                    printf("\nOpção inválida\n");
                    break;
                }

            } while (enrollment != 0);

            break;
        }

        case 4: {
            int report;

            do {
                reportsSubmenu();
                printf("\n");
                report = readInteger();

                switch (report)
                {
                case 0:
                    break;
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;

                default:
                    break;
                }

            } while (report != 0);

            break;
        }

        case 0:
            printf("\nSaindo...\n");
            break;

        default:
            printf("\nOpção inválida\n");
        }

    } while (mainMenu != 0);

    return 0;
}