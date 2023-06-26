#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define maximoUsuarios 1000

typedef struct {
    int id;
    int vacina;
    double altura;
    char nome[50];
    char email[50];
    char endereco[50];
    char sexo[20];
} Usuario;

int totalusuarios = 0;
Usuario mainUsuarios[maximoUsuarios], mainbackupUsuarios[maximoUsuarios];

int incluirUsuarios() {
    Usuario novoUsuario;
    int retorno;

    if (totalusuarios >= maximoUsuarios) {
        printf("O limite de usuários foi atingido!\n");
        return -1;
    }

    novoUsuario.id = rand() % 100000;

    printf("Digite seu nome completo: ");
    fflush(stdin);
    fgets(novoUsuario.nome, 50, stdin);

    printf("Digite seu email: ");
    scanf("%s", novoUsuario.email);

    do {
        retorno = 1;
        for (int i = 0; i < strlen(novoUsuario.email); i++) {
            if (novoUsuario.email[i] == '@') {
                retorno = 0;
                break;
            }
        }
        if (retorno == 1) {
            printf("Email inválido, tente novamente: ");
            scanf("%s", novoUsuario.email);
        }
    } while (retorno == 1);

    printf("Digite seu sexo: ");
    scanf("%s", novoUsuario.sexo);
    while (!(strcmp(novoUsuario.sexo, "masculino") == 0 || strcmp(novoUsuario.sexo, "feminino") == 0 ||
             strcmp(novoUsuario.sexo, "indiferente") == 0)) {
        printf("Sexo inválido! Digite novamente: ");
        scanf("%s", novoUsuario.sexo);
    }

    printf("Digite seu endereço: ");
    fflush(stdin);
    fgets(novoUsuario.endereco, 50, stdin);

    printf("Digite sua altura: ");
    scanf("%lf", &novoUsuario.altura);
    while (novoUsuario.altura < 1.00 || novoUsuario.altura > 2.00) {
        printf("Altura inválida, tente novamente: ");
        scanf("%lf", &novoUsuario.altura);
    }

    printf("O usuário é vacinado? (1 para sim, 0 para não): ");
    scanf("%d", &novoUsuario.vacina);
    while (!(novoUsuario.vacina == 1 || novoUsuario.vacina == 0)) {
        printf("Valor inválido, tente novamente (1 para sim, 0 para não): ");
        scanf("%d", &novoUsuario.vacina);
    }

    mainUsuarios[totalusuarios] = novoUsuario;

    totalusuarios++;

    return 0;
}

int editarUsuario() {
    char email[50];
    int retorno;

    printf("Digite o email do usuário: ");
    scanf("%s", email);

    for (int i = 0; i < totalusuarios; i++) {
        if (strcmp(mainUsuarios[i].email, email) == 0) {
            Usuario usuarioEditado;

            printf("Digite seu nome completo: ");
            fflush(stdin);
            fgets(usuarioEditado.nome, 50, stdin);

            printf("Digite seu email: ");
            scanf("%s", usuarioEditado.email);

}
}
}

