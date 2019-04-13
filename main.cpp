#include <iostream>

using namespace std;


struct Tarea
{
    int id;
    string nombre;
    string desc;
    int idEmp;

    Tarea(int,string,string,int);

    void setId(int);
    void setNombre(string);
    void setDesc(string);
    void setIdEmp(int);
    int getId();
    string getNombre();
    string getDesc();
    int getIdEmp();


};

struct Empleado
{
    int id;
    string nombre;

    Empleado(int,string);
    void setId(int);
    void setNombre(string);
    int getId();
    string getNombre();

};

template <typename T>
struct nodo
{
    T* dato;
    nodo<T>* sig;

    nodo()
    {
        dato=NULL;
        sig=NULL;
    }
};

template<typename T>
struct Iterador
{
    nodo<T>* it;

    Iterador()
    {
        it=NULL;
    }
    void iniciar(nodo<T>* p)
    {
        it=p;
    }

    bool hayElementos()
    {
        return it==NULL?0:1;
    }

    bool haySiguiente()
    {
        if(hayElementos())
        {
            if (it->sig!=NULL)
                return true;
        }
        return false;
    }

    void siguiente()
    {
        if(haySiguiente())
        {
            it=it->sig;
        }
    }

    void ultimo()
    {
        if(it!=NULL)
            while(it->sig!=NULL)
            {
                it=it->sig;
            }
    }
};

template<typename T>
struct Lista
{
    nodo<T>* base;
    Iterador<T> iterador;
    int elementos;
    Lista<T>()
    {
        elementos=0;
        base=NULL;

    }

    void agregar(T elemento)
    {

        if(base==NULL)
        {
            base=new nodo<T>();
            base->dato=&elemento;
            elementos++;
        }
        else
        {
            nodo<T>* aux=base;

            while(aux->sig!=NULL)
            {
                aux=aux->sig;
            }
            aux->sig=new nodo<T>();
            aux->sig->dato=&elemento;
            elementos++;
        }
    }

    int getElementos()
    {
        return elementos;
    }
};


int main()
{
    Empleado nuevo(12,"Juan");
    Empleado nuevo2(13,"Pedro");
    Empleado nuevo3(14,"Pedro");
    Lista<Empleado> Emp;


    Emp.agregar(nuevo);
    Emp.agregar(nuevo2);
    Emp.agregar(nuevo3);
    Emp.iterador.iniciar(Emp.base);
    cout<<"Hay elementos: "<<Emp.iterador.hayElementos()<<endl;
    cout<<"Hay siguiente: "<<Emp.iterador.haySiguiente()<<endl;
    cout<<"Hay "<<Emp.getElementos()<<" elementos"<<endl;

    while(Emp.iterador.haySiguiente())
    {
        cout<<Emp.iterador.it->dato->getId()<<" "<<Emp.iterador.it->dato->getNombre()<<endl;
        Emp.iterador.siguiente();
    }
     cout<<Emp.iterador.it->dato->getId()<<" "<<Emp.iterador.it->dato->getNombre()<<endl;





}

/***************< TAREAS ********************/

Tarea::Tarea(int i,string n,string d,int ie)
{
    id=i;
    nombre=n;
    desc=d;
    idEmp=ie;
}

void Tarea::setId(int i)
{
    id=i;
}

void Tarea::setNombre(string n)
{
    nombre=n;
}

void Tarea::setDesc(string d)
{
    desc=d;
}

void Tarea::setIdEmp(int ie)
{
    idEmp=ie;
}

int Tarea::getId()
{
    return id;
}

string Tarea::getNombre()
{
    return nombre;
}

string Tarea::getDesc()
{
    return desc;
}

int Tarea::getIdEmp()
{
    return idEmp;
}


/***************< Empleado ************************/

Empleado::Empleado(int i,string n)
{
    id=i;
    nombre=n;
}

void Empleado::setId(int i)
{
    id=i;
}

void Empleado::setNombre(string n)
{
    nombre=n;
}

int Empleado::getId()
{
    return id;
}

string Empleado::getNombre()
{
    return nombre;
}






