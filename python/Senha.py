import random
import string
def VerSenha():
    with open("senhas_geradas.txt","r") as arquivo:
        senhas=arquivo.readline()
        print("\n--- Senhas geradas ---")
        for linha in senhas:
            print(linha.strip())
def ApagarSenha():
    with open("")
while True:
    a=int(input("quantas caracteres tem que ter a senha: \n"))
    caracteres = string.ascii_letters+string.digits+string.punctuation
    senha=''.join(random.choice(caracteres)for i in range(a))
    print ("Essa é sua senha:\n",senha)
    with open("senhas_geradas.txt", "a") as arquivo:
        arquivo.write(senha + "\n")
    print("Gostaria de sair? \n" 
    "1- SIM \n" 
    "2- NÃO")
    b= int(input(">"))
    if b==1:
        break
    elif b==2:
        print("~~~~~~~~~~~~O que você gostaria de fazer: \n" \
        "1 - Gerar nova senha\n" \
        "2- Ver senhas já geradas\n" \
        "3- Excluir todas as senhas \n")
        x=int(input(">"))
        if x==1