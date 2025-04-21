#include <stdio.h>
#include <string.h>
#define TAM 100


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
    int codigo;              
    char nome[50];            
    int semestre;             
    int codProfessor;         
    int alunosIds[TAM];      
    int totalAlunos;         
} Disciplina;

Disciplina listarDisciplinas[TAM];
int qtdDisciplinas = 0;

int main() {
    Aluno listarAlunos[TAM];
    Professor listarProfessores[TAM];
    int qtdAlunos = 0;
    int qtdProfessores = 0;
    int opcao;

    do {
        printf("\n\n");
        printf("\t***********************************************************\n");
        printf("\t**** Controle de Funcionamento - Escola Lirio dos Vales ***\n");
        printf("\t***********************************************************\n\n");

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
                        
                    // Cadastro de Alunos
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
                                    
                                    //Excluir alunos

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


                                    //Atualizar alunos
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
                                                getchar();
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

                        // Cadastro de Professores
                        
                        case 2:
                            printf("\nCadastro de Professores:\n");
                            int subopcao_prof;
                            do {
                              
                                printf("1 - Incluir\n");
                                printf("2 - Excluir\n");
                                printf("3 - Atualizar\n");
                                printf("0 - Voltar\n");
                                scanf("%d", &subopcao_prof);
                                switch (subopcao_prof) {
                                    
                                    // incluir professor 
                                        case 1: {
                                            if (qtdProfessores < TAM) {
                                                Professor novo_prof;

                                                printf("\nIncluir Professor\n");
                                                printf("Matrícula: ");
                                                scanf("%d", &novo_prof.matricula);
                                                getchar(); 

                                                printf("Nome: ");
                                                fgets(novo_prof.nome, sizeof(novo_prof.nome), stdin);
                                                novo_prof.nome[strcspn(novo_prof.nome, "\n")] = '\0';

                                                printf("Sexo (M/F): ");
                                                scanf(" %c", &novo_prof.sexo); 

                                                printf("CPF: ");
                                                scanf("%s", novo_prof.cpf);

                                                printf("Data de nascimento (dd mm aaaa): ");
                                                scanf("%d %d %d", &novo_prof.nascimento.dia, &novo_prof.nascimento.mes, &novo_prof.nascimento.ano);

                                                listarProfessores[qtdProfessores] = novo_prof;
                                                qtdProfessores++;

                                                printf("\nProfessor cadastrado com sucesso!\n");
                                            } else {
                                                printf("O limite foi atingido!\n");
                                            }
                                            break;
                                        }
                                        
                                        // Excluir professor
                                        case 2: {
                                            printf("\n#### Lista de Professores ####\n");
                                            for (int i = 0; i < qtdProfessores; i++) {
                                                printf("Matrícula: %d - Nome: %s - Sexo: %c\n", listarProfessores[i].matricula, listarProfessores[i].nome, listarProfessores[i].sexo);
                                            }
                                            
                                            int mat_p;
                                            printf("\nDigite a matrícula do professor que deseja excluir: ");
                                           
                                            scanf("%d", &mat_p);

                                            int achou_p = 0;
                                            for (int i = 0; i < qtdProfessores; i++) {
                                                if (listarProfessores[i].matricula == mat_p) {
                                                    achou_p = 1;
                                                    for (int j = i; j < qtdProfessores - 1; j++) {
                                                        listarProfessores[j] = listarProfessores[j + 1];
                                                    }
                                                    qtdProfessores--;
                                                    break;
                                                }
                                            }

                                            if (achou_p) {
                                                printf("Professor excluído com sucesso!\n");
                                            } else {
                                                printf("Professor com matrícula %d não encontrado.\n", mat_p);
                                            }
                                            break;
                                        }

                                        // Atualizar professor
                                        case 3: {
                                            printf("\nDigite a matrícula do professor que deseja atualizar: ");
                                            int mat_p1;
                                            scanf("%d", &mat_p1);

                                            int encontrado_p = 0;
                                            for (int i = 0; i < qtdProfessores; i++) {
                                                if (listarProfessores[i].matricula == mat_p1) {
                                                    encontrado_p = 1;

                                                    printf("\nDados atuais do professor:\n");
                                                    printf("Matrícula: %d\n", listarProfessores[i].matricula);
                                                    printf("Nome: %s\n", listarProfessores[i].nome);
                                                    printf("Sexo: %c\n", listarProfessores[i].sexo);
                                                    printf("CPF: %s\n", listarProfessores[i].cpf);
                                                    printf("Nascimento: %02d/%02d/%04d\n", listarProfessores[i].nascimento.dia, listarProfessores[i].nascimento.mes, listarProfessores[i].nascimento.ano);

                                                    printf("\nDigite os novos dados:\n");

                                                    printf("Nome: ");
                                                    getchar();
                                                    fgets(listarProfessores[i].nome, sizeof(listarProfessores[i].nome), stdin);
                                                    listarProfessores[i].nome[strcspn(listarProfessores[i].nome, "\n")] = '\0';

                                                    printf("Sexo (M/F): ");
                                                    scanf(" %c", &listarProfessores[i].sexo);

                                                    printf("CPF: ");
                                                    scanf("%s", listarProfessores[i].cpf);

                                                    printf("Data de nascimento (dd mm aaaa): ");
                                                    scanf("%d %d %d", &listarProfessores[i].nascimento.dia, &listarProfessores[i].nascimento.mes, &listarProfessores[i].nascimento.ano);

                                                    printf("\nProfessor atualizado com sucesso!\n");
                                                    break;
                                                }
                                            }

                                            if (!encontrado_p) {
                                                printf("Professor com matrícula %d não encontrado.\n", mat_p1);
                                            }
                                            break;
                                        }

                                        case 0:
                                            printf("Voltando ao menu de cadastro...\n");
                                            break;

                                        default:
                                            printf("Opção inválida.\n");
                                    }
                                } while (subopcao_prof != 0);
                            
                            break;
                            
                            
                          // Cadastro de disciplinas

                        case 3: {
                        printf("\nCadastro de Disciplinas:\n");
                        int subopcao_disc;
                        do {
                            printf("1 - Incluir\n");
                            printf("2 - Excluir\n");
                            printf("3 - Atualizar\n");
                            printf("4 - Adicionar Aluno\n");
                            printf("5 - Remover Aluno\n");
                            printf("0 - Voltar\n");
                            scanf("%d", &subopcao_disc);
                    
                            switch (subopcao_disc) {
                            
                            //Incluir disciplina                                    
                            case 1: {
                                    if (qtdDisciplinas < TAM) {
                                        Disciplina nova_disc;
                                
                                        printf("\nIncluir Disciplina\n");
                                
                                        getchar(); 
                                        printf("Nome da disciplina: ");
                                        fgets(nova_disc.nome, sizeof(nova_disc.nome), stdin);
                                        nova_disc.nome[strcspn(nova_disc.nome, "\n")] = '\0';
                                
                                        printf("Código da disciplina: ");
                                        scanf("%d", &nova_disc.codigo);
                                
                                        printf("Semestre da disciplina: ");
                                        scanf("%d", &nova_disc.semestre);
                                
                                        printf("Código do professor responsável: ");
                                        scanf("%d", &nova_disc.codProfessor);
                                
                                        nova_disc.totalAlunos = 0;
                                
                                        listarDisciplinas[qtdDisciplinas++] = nova_disc;
                                
                                        printf("\nDisciplina cadastrada com sucesso!\n");
                                    } else {
                                        printf("O limite de disciplinas foi atingido!\n");
                                    }
                                    break;
                                }
                                // Excluir disciplina
                                   
                                case 2: {
                                    printf("\n#### Lista de Disciplinas ####\n");
                                    for (int i = 0; i < qtdDisciplinas; i++) {
                                        printf("ID: %d - Nome: %s - Professor: %d\n",
                                               listarDisciplinas[i].codigo, listarDisciplinas[i].nome, listarDisciplinas[i].codProfessor);
                                    }
                    
                                    int id;
                                    printf("\nDigite o codigo da disciplina que deseja excluir: ");
                                    scanf("%d", &id);
                    
                                    int achou = 0;
                                    for (int i = 0; i < qtdDisciplinas; i++) {
                                        if (listarDisciplinas[i].codigo == id) {
                                            achou = 1;
                                            for (int j = i; j < qtdDisciplinas - 1; j++) {
                                                listarDisciplinas[j] = listarDisciplinas[j + 1];
                                            }
                                            qtdDisciplinas--;
                                            break;
                                        }
                                    }
                    
                                    if (achou) {
                                        printf("Disciplina excluída com sucesso!\n");
                                    } else {
                                        printf("Disciplina com ID %d não encontrada.\n", id);
                                    }
                                    break;
                                }
                                
                                //Atualizar disciplina
                              case 3: {
                                    int id;
                                    printf("\nDigite o código da disciplina que deseja atualizar: ");
                                    scanf("%d", &id);
                                
                                    int encontrado = 0;
                                    for (int i = 0; i < qtdDisciplinas; i++) {
                                        if (listarDisciplinas[i].codigo == id) {
                                            encontrado = 1;
                                
                                            printf("\nDados atuais:\n");
                                            printf("Código: %d\n", listarDisciplinas[i].codigo);
                                            printf("Nome: %s\n", listarDisciplinas[i].nome);
                                            printf("Semestre: %d\n", listarDisciplinas[i].semestre);
                                            printf("Professor: %d\n", listarDisciplinas[i].codProfessor);
                                
                                            printf("\nDigite os novos dados:\n");
                                
                                            getchar(); // limpar buffer
                                            printf("Nome: ");
                                            fgets(listarDisciplinas[i].nome, sizeof(listarDisciplinas[i].nome), stdin);
                                            listarDisciplinas[i].nome[strcspn(listarDisciplinas[i].nome, "\n")] = '\0';
                                
                                            printf("Novo código da disciplina: ");
                                            scanf("%d", &listarDisciplinas[i].codigo);
                                
                                            printf("Novo semestre: ");
                                            scanf("%d", &listarDisciplinas[i].semestre);
                                
                                            printf("Novo código do professor: ");
                                            scanf("%d", &listarDisciplinas[i].codProfessor);
                                
                                            printf("Disciplina atualizada com sucesso!\n");
                                            break;
                                        }
                                    }
                                
                                    if (!encontrado) {
                                        printf("Disciplina com código %d não encontrada.\n", id);
                                    }
                                
                                    break;
                                }
                                    
                                //Adicionar aluno
                                case 4: {
                                    int idDisc, idAluno;
                                    printf("Informe o código da disciplina: ");
                                    scanf("%d", &idDisc);
                                    printf("Informe o código do aluno para adicionar: ");
                                    scanf("%d", &idAluno);
                    
                                    int achou = 0;
                                    for (int i = 0; i < qtdDisciplinas; i++) {
                                        if (listarDisciplinas[i].codigo == idDisc) {
                                            listarDisciplinas[i].alunosIds[listarDisciplinas[i].totalAlunos++] = idAluno;
                                            printf("Aluno adicionado à disciplina.\n");
                                            achou = 1;
                                            break;
                                        }
                                    }
                                    if (!achou) {
                                        printf("Disciplina não encontrada.\n");
                                    }
                                    break;
                                } 
                                 
                              //Remover aluno
                              case 5: {
                                    int idDisc, idAluno;
                                    printf("ID da disciplina: ");
                                    scanf("%d", &idDisc);
                                    printf("ID do aluno a remover: ");
                                    scanf("%d", &idAluno);
                    
                                    int achou = 0;
                                    for (int i = 0; i < qtdDisciplinas; i++) {
                                        if (listarDisciplinas[i].codigo == idDisc) {
                                            for (int j = 0; j < listarDisciplinas[i].totalAlunos; j++) {
                                                if (listarDisciplinas[i].alunosIds[j] == idAluno) {
                                                    for (int k = j; k < listarDisciplinas[i].totalAlunos - 1; k++) {
                                                        listarDisciplinas[i].alunosIds[k] = listarDisciplinas[i].alunosIds[k + 1];
                                                    }
                                                    listarDisciplinas[i].totalAlunos--;
                                                    printf("Aluno removido.\n");
                                                    achou = 1;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                    
                                    if (!achou) {
                                        printf("Disciplina ou aluno não encontrado.\n");
                                    }
                                    break;
                                }
                                                                
                              case 0:
                                    printf("Voltando ao menu...\n");
                                    break;
                    
                                default:
                                    printf("Opção inválida.\n");
                            }
                    
                        } while (subopcao_disc != 0);
                        break;
                    }
                    
                        case 0:
                            printf("Voltando ao menu principal...\n");
                            break;

                        default:
                            printf("Opção inválida.\n");
                    }
                } while (cadastro != 0);
                break;
            }


             //Relatório: alunos   

            case 2:
                printf("Você escolheu a opção 2: Relatórios: alunos\n");
                for (int i = 0; i < qtdAlunos; i++) {
                    printf("Matrícula: %d - Nome: %s - Sexo: %c\n", listarAlunos[i].matricula, listarAlunos[i].nome, listarAlunos[i].sexo);
                }
                break;






             //Relatório: Professores  
            case 3:
                printf("Você escolheu a opção 3: Relatórios: professores\n");
                
                for (int i = 0; i < qtdProfessores; i++) {
                    printf("Matrícula: %d - Nome: %s - Sexo: %c\n", listarProfessores[i].matricula, listarProfessores[i].nome, listarProfessores[i].sexo);
                }
                break;

             //Relatório: Disciplinas  
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
                          
                                
                                
                                
                    
