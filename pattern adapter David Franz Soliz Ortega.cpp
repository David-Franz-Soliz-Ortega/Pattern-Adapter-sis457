#include<iostream>
using namespace std;
//la interfaz del tirnagulo
class Target {
public:
	virtual ~Target() = default;
	
	virtual float Request() const {
		cout<<"Iniciando entrega de triangulo"<<endl;
		return 0;
	}
};
//medidas asignadas por defecto

class Adaptee {
public:
	float SpecificRequest() const {
		float base=3;
		float altura=4;
		cout<<"Base: "<<base<<endl;
		cout<<"Altura: "<<altura<<endl;
		cout<<"Area: ";
		return base*altura/2;
	}
	
};

// configura el tamaño a la solicitud del cliente
class Adapter : public Target {
private:
	Adaptee *adaptee_;
	
public:
	Adapter(Adaptee *adaptee) : adaptee_(adaptee) {}
	float Request() const override {
	float base;
	float altura;
	float area;

	cout<<"Base nueva:"<<endl;
	cin>>base;
	cout<<"Altura nueva:"<<endl;
	cin>>altura;
	area=(base*altura/2);
	cout<<"Area nueva: ";
	return area;
	}
};


void ClientCode(const Target *target) {
	cout<<target->Request();
}

int main() {
	std::cout << "Necesito que imprima un objeto con forma de triangulo\n";
	Target *target = new Target;
	ClientCode(target);
	std::cout << "\n\n";
	Adaptee *adaptee = new Adaptee;
	std::cout << "No es lo que necesito, tiene las medidas incorrectas"<<endl;
	cout << "\n";
	cout << " triangulo original: " << adaptee->SpecificRequest();
	cout << "\n\n";
	cout << "A ver lo modificare para adaptar el tamaño\n";
	Adapter *adapter = new Adapter(adaptee);
	ClientCode(adapter);
	cout << "\n";
	
	delete target;
	delete adaptee;
	delete adapter;
	
	return 0;
}
