import tkinter as tk

# Criar a janela
janela = tk.Tk()
janela.title("Bolinha quicando nas paredes")

largura = 400
altura = 400

janela.geometry(f"{largura}x{altura}")

# Criar o canvas
canvas = tk.Canvas(janela, width=largura, height=altura, bg="black")
canvas.pack()

# Criar a bolinha
raio = 20
x_inicial =2
y_inicial =3
bola = canvas.create_oval(x_inicial, y_inicial, x_inicial + raio, y_inicial + raio, fill="blue")

# Velocidade inicial
vx = 10
vy = 10

# Função de movimento
def mover():
    global vx, vy

    # Pega as coordenadas atuais da bola
    x1, y1, x2, y2 = canvas.coords(bola)

    # Verifica colisão com as bordas
    if x1 <= 0 or x2 >= largura:
        vx = -vx  # inverte a direção horizontal
    if y1 <= 0 or y2 >= altura:
        vy = -vy  # inverte a direção vertical

    # Move a bola
    canvas.move(bola, vx, vy)
    
    # Chama de novo após 20 milissegundos
    janela.after(20, mover)

# Inicia o movimento
mover()

# Inicia a interface
janela.mainloop()
