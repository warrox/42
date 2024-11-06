// CLASSE ABSTRAITE
class Mamifere:
    def marcher(self) = 0:
        pass
    def courrir(self):
        print("Je cours")

// INTERFACE
class Mamifere:
    def marcher(self) = 0:
        pass
    def courrir(self) = 0:
        pass


class Chat(Mamifere):
    def marcher(slef):
        print("Je marche")

    def miauler(self):
        print("Je miaule et je suis un chat")

class Oiseau:
    def marcher(self):
        print("Je suis un oiseau et je marche")


chat = Chat()
oiseau = Oiseau()

chat.marcher()
mami.marcher()
oiseau.marcher()

==> Polymorphisme est le fait de pouvoir appeler la meme methode sur the instance / class qui sont differentes, les methodes communes peuvent etre lie a lheritage ou NON
