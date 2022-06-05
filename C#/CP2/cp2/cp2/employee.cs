namespace cp2;

public class employee
{
    private string name = "";
    private double salary = 0;
    private string modality = "";
    private double ISS = 0;
    private double AFP = 0;
    private double income = 0;
    private bool gender = false;
    private int birthYear = 0;

    public employee(string name, double salary, string modality, bool gender, int birthYear)
    {
        this.name = name;
        this.salary = salary;
        this.modality = modality;
        this.gender = gender;
        this.birthYear = birthYear;
    }

    public string Name
    {
        get => name;
        set => name = value;
    }

    public double Salary
    {
        get => salary;
        set => salary = value;
    }

    public string Modality
    {
        get => modality;
        set => modality = value;
    }

    public double Iss
    {
        get => ISS;
        set => ISS = value;
    }

    public double Afp
    {
        get => AFP;
        set => AFP = value;
    }

    public double Income
    {
        get => income;
        set => income = value;
    }

    public bool Gender
    {
        get => gender;
        set => gender = value;
    }

    public int BirthYear
    {
        get => birthYear;
        set => birthYear = value;
    }

    public double calculateDeduction()
    {
        double deduction = 0;
        if (modality == "planilla")
        {
            ISS = salary * 0.03;
            AFP = salary * 0.07;
            income = salary * 0.1;
        }
        else if (modality == "servicio profesional")
        {
            ISS = 0;
            AFP = 0;
            income = salary * 0.1;
        }
        deduction = ISS + AFP + income;

        return deduction;
    }

    public bool calculateWithdrawal()
    {
        bool withdrawal = false;
        //Female == true
        if (gender == true && (2022 - birthYear) >= 55)
        {
            withdrawal = true;
        }
        //Male == false
        else if (gender == false && (2022 - birthYear) >= 60)
        {
            withdrawal = true;
        }

        return withdrawal;
    }

    public override string ToString()
    {
        Console.Write("\nDatos de Empleado");
        return "\nNombre: " +name + "\nSalario: $" +salary +"\nModalidad: " +modality +"\nGenero: " +gender +"\nAnio de nacimiento: "+ BirthYear;
    }
}