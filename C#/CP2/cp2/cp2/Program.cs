namespace cp2
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            /*Escribe tu programa, pero antes debes analizar el diagrama de clases en la guia
             * https://meaguilar.github.io/POO/Evaluaciones/cp2/#0
             * 
             * Resultado esperado imprimir en pantalla los datos del empleado,
             * su deducción salarial, y su salario aplicada las deducciones y  si es apto para el retiro según su edad y género. 
             */
            employee employee1 = new employee("Douglas", 1500, "planilla", false, 1975);
            employee employee2 = new employee("Diana", 4500, "servicio profesional", true, 1950);
            Console.WriteLine(employee1.ToString());
            Console.WriteLine("Deduccion: $" + employee1.calculateDeduction());
            Console.WriteLine("Salario: $" + (employee1.Salary - employee1.calculateDeduction()));
            Console.WriteLine("Retiro: " + employee1.calculateWithdrawal());
            Console.WriteLine(employee2.ToString());
            Console.WriteLine("Deduccion: $" + employee2.calculateDeduction());
            Console.WriteLine("Salario: $" + (employee2.Salary - employee2.calculateDeduction()));
            Console.WriteLine("Retiro: " + employee2.calculateWithdrawal());
        }
    }
}