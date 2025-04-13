#include <stdio.h>
#include <string.h>
#define TAM 80

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    int matricula;
    char nome[150];
    char sexo;
    char cpf[15];
    Data nascimento;
} Aluno;

typedef struct {
    int matricula;
    char nome[150];
    char sexo;
    char cpf[15];
    Data nascimento;
} Professor;

typedef struct {
    char nome[150];
    char codigo[10];
    float semestre;
    Professor professor;  
} Disciplina;

int main() {
    Aluno listarAlunos[TAM];
    int qtdAlunos = 0;
    int opcao;

    do {
        printf("\n\n");
        printf("\t***********************************************************\n");
        printf("\t**** Controle de Funcionamento - Escola Lírio dos Vales ****\n");
        printf("\t***********************************************************\n");

        printf("Escolha uma opção:\n");
        printf("1 - Cadastrar (alunos, professores e disciplinas)\n");
        printf("2 - Relatórios: alunos\n");
        printf("3 - Relatórios: professores\n");
        printf("4 - Relatórios: Disciplinas\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                int cadastro;
                do {
                    printf("\nVocê escolheu a opção 1: Cadastrar\n");
                    printf("1 - Cadastro de Alunos\n");
                    printf("2 - Cadastro de Professores\n");
                    printf("3 - Cadastro de Disciplinas\n");
                    printf("0 - Voltar\n");
                    scanf("%d", &cadastro);

                    switch (cadastro) {
                        case 1: {
                            int subopcao;
                            do {
                                printf("\nCadastro de Alunos:\n");
                                printf("1 - Incluir\n");
                                printf("2 - Excluir\n");
                                printf("3 - Atualizar\n");
                                printf("0 - Voltar\n");
                                scanf("%d", &subopcao);

                                switch (subopcao) {
                                    case 1: {
                                        if (qtdAlunos < TAM) {
                                            Aluno novo;

                                            printf("\nIncluir Aluno\n");
                                            printf("Matrícula: ");
                                            scanf("%d", &novo.matricula);
                                            getchar(); 

                                            printf("Nome: ");
                                            fgets(novo.nome, sizeof(novo.nome), stdin);
                                            novo.nome[strcspn(novo.nome, "\n")] = '\0';

                                            printf("Sexo (M/F): ");
                                            scanf(" %c", &novo.sexo); 

                                            printf("CPF: ");
                                            scanf("%s", novo.cpf);

                                            printf("Data de nascimento (dd mm aaaa): ");
                                            scanf("%d %d %d", &novo.nascimento.dia, &novo.nascimento.mes, &novo.nascimento.ano);

                                            listarAlunos[qtdAlunos] = novo;
                                            qtdAlunos++;

                                            printf("\nAluno cadastrado com sucesso!\n");
                                        } else {
                                            printf("O limite foi atingido!\n");
                                        }
                                        break;
                                    }

                                    case 2: {
                                        printf("\n#### Lista de Alunos ####\n");
                                        for (int i = 0; i < qtdAlunos; i++) {
                                            printf("Matrícula: %d - Nome: %s - Sexo: %c\n", listarAlunos[i].matricula, listarAlunos[i].nome, listarAlunos[i].sexo);
                                        }

                                        printf("\nDigite a matrícula do aluno que deseja excluir: ");
                                        int mat;
                                        scanf("%d", &mat);

                                        int achou = 0;
                                        for (int i = 0; i < qtdAlunos; i++) {
                                            if (listarAlunos[i].matricula == mat) {
                                                achou = 1;
                                                for (int j = i; j < qtdAlunos - 1; j++) {
                                                    listarAlunos[j] = listarAlunos[j + 1];
                                                }
                                                qtdAlunos--;
                                                break;
                                            }
                                        }

                                        if (achou) {
                                            printf("Aluno excluído com sucesso!\n");
                                        } else {
                                            printf("Aluno com matrícula %d não encontrado.\n", mat);
                                        }
                                        break;
                                    }

                                    case 3: {
                                        printf("\nDigite a matrícula do aluno que deseja atualizar: ");
                                        int mat;
                                        scanf("%d", &mat);

                                        int encontrado = 0;
                                        for (int i = 0; i < qtdAlunos; i++) {
                                            if (listarAlunos[i].matricula == mat) {
                                                encontrado = 1;

                                                printf("\nDados atuais do aluno:\n");
                                                printf("Matrícula: %d\n", listarAlunos[i].matricula);
                                                printf("Nome: %s\n", listarAlunos[i].nome);
                                                printf("Sexo: %c\n", listarAlunos[i].sexo);
                                                printf("CPF: %s\n", listarAlunos[i].cpf);
                                                printf("Nascimento: %02d/%02d/%04d\n", listarAlunos[i].nascimento.dia, listarAlunos[i].nascimento.mes, listarAlunos[i].nascimento.ano);

                                                printf("\nDigite os novos dados:\n");

                                                printf("Nome: ");
                                                getchar(); // Limpar buffer
                                                fgets(listarAlunos[i].nome, sizeof(listarAlunos[i].nome), stdin);
                                                listarAlunos[i].nome[strcspn(listarAlunos[i].nome, "\n")] = '\0';

                                                printf("Sexo (M/F): ");
                                                scanf(" %c", &listarAlunos[i].sexo);

                                                printf("CPF: ");
                                                scanf("%s", listarAlunos[i].cpf);

                                                printf("Data de nascimento (dd mm aaaa): ");
                                                scanf("%d %d %d", &listarAlunos[i].nascimento.dia, &listarAlunos[i].nascimento.mes, &listarAlunos[i].nascimento.ano);

                                                printf("\nAluno atualizado com sucesso!\n");
                                                break;
                                            }
                                        }

                                        if (!encontrado) {
                                            printf("Aluno com matrícula %d não encontrado.\n", mat);
                                        }
                                        break;
                                    }

                                    case 0:
                                        printf("Voltando ao menu de cadastro...\n");
                                        break;

                                    default:
                                        printf("Opção inválida.\n");
                                }
                            } while (subopcao != 0);
                            break;
                        }

                        case 2:
                            printf("\nCadastro de Professores:\n");
                            printf("Função ainda não implementada.\n");
                            break;

                        case 3:
                            printf("\nCadastro de Disciplinas:\n");
                            printf("Função ainda não implementada.\n");
                            break;

                        case 0:
                            printf("Voltando ao menu principal...\n");
                            break;

                        default:
                            printf("Opção inválida.\n");
                    }
                } while (cadastro != 0);
                break;
            }

            case 2:
                printf("Você escolheu a opção 2: Relatórios: alunos\n");
                for (int i = 0; i < qtdAlunos; i++) {
                    printf("Matrícula: %d - Nome: %s - Sexo: %c\n", listarAlunos[i].matricula, listarAlunos[i].nome, listarAlunos[i].sexo);
                }
                break;

            case 3:
                printf("Você escolheu a opção 3: Relatórios: professores\n");
                break;

            case 4:
                printf("Você escolheu a opção 4: Relatórios: Disciplinas\n");
                break;

            case 0:
                printf("Encerrando sessão...\n");
                break;

            default:
                printf("Opção inválida. Tente novamente!\n");
        }
    } while (opcao != 0);

    return 0;
}
