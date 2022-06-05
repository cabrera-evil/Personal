using System;
//Escribe tu programa sobre una calculadora que realice las 4 operaciones basicas
        
/*
 * Requerimientos:
 *
 * Realizar las operaciones según la opción que seleccione el usuario, mediante un menú repetitivo
 * Programar una opcion para salir del menú.
 * 
 */
namespace CP1
{
  internal class Program
  {
    public static void Main(string[] args)
    {
        int option = 0, total = 0;
        int[] num = {0,0};
        bool exit = false;
        do
        {
            Console.WriteLine("\tMenu");
            Console.WriteLine("1. Suma");
            Console.WriteLine("2. Resta");
            Console.WriteLine("3. Multiplicacion");
            Console.WriteLine("4. Division");
            Console.WriteLine("5. Salir");
            Console.Write("Tu opcion: ");
            option = Convert.ToInt32(Console.ReadLine());
            switch (option)
            {
                case 1:
                    //Suma
                    int sum = 0;
                    for (int i = 0; i < 2; i++)
                    {
                        Console.Write("Ingresar numero " + (i + 1) +": ");
                        num[i] = Convert.ToInt32(Console.ReadLine());
                        sum += num[i];
                    }
                    Console.WriteLine("La suma es: " +sum);
                    break;
                case 2:
                    //Resta
                    int substraction = 0;
                    for (int i = 0; i < 2; i++)
                    {
                        Console.Write("Ingresar numero " + (i + 1) +": ");
                        num[i] = Convert.ToInt32(Console.ReadLine());
                    }
                    substraction = (num[0] - num[1]);
                    Console.WriteLine("La resta es: " +substraction);
                    break;
                case 3:
                    //Multiplicacion
                    int multiplication = 0;
                    for (int i = 0; i < 2; i++)
                    {
                        Console.Write("Ingresar numero " + (i + 1) +": ");
                        num[i] = Convert.ToInt32(Console.ReadLine());
                    }
                    multiplication = (num[0] * num[1]);
                    Console.WriteLine("La multiplicacion es: " +multiplication);
                    break;
                case 4:
                    //Division
                    int division = 0;
                    for (int i = 0; i < 2; i++)
                    {
                        Console.Write("Ingresar numero " + (i + 1) +": ");
                        num[i] = Convert.ToInt32(Console.ReadLine());
                    }
                    division = (num[0] / num[1]);
                    Console.WriteLine("La division es: " +division);
                    break;
                case 5:
                    //Salir
                    exit = true;
                    break;
                default:
                    Console.WriteLine("Opcion incorrecta");
                    break;
            }
        } while (exit != true);
    }
  }
}