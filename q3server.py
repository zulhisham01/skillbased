import random
import socket
import threading

quotes = ["The way to get started is to quit talking and begin doing - Walt Disney",
          "Weaknesses are just strengths in the wrong enviroment - Marianne Cantwell",
          "Wake up determined, go to bed satisfied - Dwayne Johnson"]

def handle_client(client_socket):
    quote = random.choice(quotes)
    client_socket.send(quote.encode())
    client_socket.close()

def main():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(('', 8888))
    server_socket.listen(5)

    print("QOTD server is listening for incoming connections...")

    while True:
        client_socket, addr = server_socket.accept()
        print(f"Connected by {addr}")
        client_handler = threading.Thread(target=handle_client, args=(client_socket,))
        client_handler.start()



if __name__ == '__main__':
    main()
