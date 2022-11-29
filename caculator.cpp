#include <iostream>
#include <stack>
#include <string>
using namespace std;
#define p 3.14159265
#define INT_MAX 2147483647


int integer_part(int n)
{
	int start=0,end=n-1;
    int mid;
	while(start<=end)
	{
		 mid=((end-start)/2)+start;
		if(mid*mid==n ) return mid;
		else if(mid*mid>n ) end=mid-1;
		else start=mid+1;
	}
	return mid-1;
}
double more_pre(int n,int pre,int integer_part)
{
    double factor=1;
    double ans=integer_part;
    for(int i=0;i<pre;i++)
    {
        factor=factor/10;
        for(double j=ans;j*j<n;j=j+factor)
        {
            ans = j;
        }
    }
    return ans ;
}

double root(int n)
{
    int int_part=integer_part(n);
    return more_pre(n,5,int_part);

}


double pow(double a, int b)
{
    double ans = a;
    if (b == 0)
        return 1;
    for (int i = 1; i < b; i++)
    {
        ans *= a;
    }
    return ans;
}

double sin(double a)
{
    while (a >= 2 * p)
    {
        a -= (2 * p);
    }
    // cout<<a<<" ";
    double fact[9];
    fact[0] = 1;                // 1
    fact[1] = 6;                // 3
    fact[2] = 120;              // 5
    fact[3] = 5040;             // 7
    fact[4] = 362880;           // 9
    fact[5] = 39916800;         // 11
    fact[6] = 6227020800;       // 13
    fact[7] = 1307674368000;    // 15
    fact[8] = 6402373710000000; // 17

    double ans = 0;

    for (int i = 0; i < 9; i++)
    {
        ans += ((double)(((pow(-1, i)) * pow(a, ((2 * i) + 1)))) / fact[i]);
    }
    return ans;
}
double cos(double a)
{
    while (a >= 2 * p)
    {
        a -= (2 * p);
    }
    // cout<<a<<" ";

    double fact[9];
    fact[0] = 1;              // 1
    fact[1] = 2;              // 2
    fact[2] = 24;             // 4
    fact[3] = 720;            // 6
    fact[4] = 40320;          // 8
    fact[5] = 3628800;        // 10
    fact[6] = 479001600;      // 12
    fact[7] = 87178291200;    // 14
    fact[8] = 20922789900000; // 16

    double ans = 0;

    for (int i = 0; i < 9; i++)
    {
        ans += ((((pow(-1, i)) * pow(a, (2 * i)))) / fact[i]);
    }
    return ans;
}
double tan(double a)
{
    while (a > 2 * p)
    {
        a -= (2 * p);
    }
    if (a == p / 2 || a == (3 * p) / 2)
        return INT_MAX;
    return sin(a) / cos(a);
}
double cot(double a)
{
    while (a > 2 * p)
    {
        a -= (2 * p);
    }
    if (a == 0 || a == p)
        return INT_MAX;

    return ((double)1 / tan(a));
}
double cosec(double a)
{
    while (a > 2 * p)
    {
        a -= (2 * p);
    }
    if (a == 0 || a == p || a == 2 * p)
        return INT_MAX;
    return ((double)1 / sin(a));
}
double sec(double a)
{
    while (a > 2 * p)
    {
        a -= (2 * p);
    }
    if (a == p / 2 || a == (3 * p) / 2)
        return INT_MAX;
    return ((double)1 / cos(a));
}

// sin S cos C cot c tan T sec s cosec t

// expresstion
// matrix
// qradratic equation
// square root
// complex number

int preference(char a)
{
    if (a == '+')
        return 2;
    if (a == '-')
        return 2;
    if (a == '(')
        return 0;
    if (a == '*' || a == '/')
        return 3;
    if (a == '^')
        return 0;
    if ((a == 'S' || a == 'C' || a == 'c' || a == 's' || a == 'T' || a == 't'))
        return 1;
    return 0;
}

string to_pre(string s)
{
    stack<char> ss;
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= '0' && s[i] <= '9') || s[i] == 'p')
        {
            while (i < s.length() && ((s[i] >= '0' && s[i] <= '9') || s[i] == 'p'))
            {
                ans += s[i];
                i++;
            }
            ans += ',';
        }
        if (i < s.length())
        {
            if (s[i] == '(')
            {
                ss.push(s[i]);
            }
            else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            {
                ss.push(s[i]);
            }
            else if (s[i] == ')')
            {
                while (ss.top() != '(')
                {
                    ans += ss.top();
                    ss.pop();
                }
                ss.pop();
            }
            else
            {
                while (!ss.empty() && preference(ss.top()) > preference(s[i]))
                {
                    ans += ss.top();
                    ss.pop();
                }
                ss.push(s[i]);
            }
        }
    }
    while (!ss.empty())
    {
        ans += ss.top();
        ss.pop();
    }
    // cout << ans;
    return ans;
}
double expression_eval(string s)
{
    stack<double> ss;
    double ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            int d = 0;
            while (s[i] >= '0' && s[i] <= '9')
            {
                d = (d * 10) + (s[i] - '0');
                // cout<<d<<endl;
                i++;
            }
            ss.push(d);
        }
        if (i < s.length())
        {
            if (s[i] == ',')
                continue;
            else if (s[i] == 'p')
            {
                ss.push(p);
            }
            else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            {
                double b = ss.top();

                ss.pop();
                double aa = 0;
                // sin S cos C cot c tan T sec s cosec t
                if (s[i] == 'S')
                {
                    aa += sin(b);
                }
                else if (s[i] == 's')
                {
                    aa += sec(b);
                }
                else if (s[i] == 'C')
                {
                    aa += cos(b);
                }
                else if (s[i] == 'c')
                {
                    aa += cot(b);
                }
                else if (s[i] == 'T')
                {
                    aa += tan(b);
                }
                else if (s[i] == 't')
                {
                    aa += cosec(b);
                }
                ss.push(aa);
            }
            else
            {
                double a = ss.top();
                ss.pop();
                double b = ss.top();
                ss.pop();
                double aa = 0;

                // cout<<a<<" "<<b<<endl;
                if (a == INT_MAX || b == INT_MAX)
                {
                    aa = INT_MAX;
                }
                else if (s[i] == '+')
                {
                    aa += (a + b);
                }
                else if (s[i] == '-')
                {
                    aa += (b - a);
                }
                else if (s[i] == '*')
                {
                    aa += (a * b);
                }
                else if (s[i] == '/')
                {
                    aa += ((double)b / a);
                }
                else if (s[i] == '^')
                {
                    aa += pow(b, a);
                }

                ss.push(aa);
            }
        }
    }
    // cout<<ss.top();
    ans += (ss.top());
    return ans;
}

int expression()
{
    system("cls");
    string s;
    cout << "enter the expression : ";
    getline(cin, s);
    s = to_pre(s);
    if (expression_eval(s) == INT_MAX)
    {
        cout << "ANSWER : " << char(236);
    }
    else
    {
        cout << "ANSWER : " << expression_eval(s);
    }
}

// matrices
void add_mat(int **matA, int **matB, int n1, int m1, int n2, int m2)
{
    system("cls");
    if (n1 != n2 || m1 != m2)
    {
        cout << "\nADDITION IS NOT POSSIBLE . ";
        return;
    }
    int **mat = new int *[n1];
    for (int i = 0; i < n1; i++)
    {
        mat[i] = new int[m2];
    }

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            mat[i][j] = matA[i][j] + matB[i][j];
        }
    }
    cout << "\nANSWER : \n";
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << "TO STORE THE RESULTANT MATRIX : ENTER 1 ELSE ENTER  0 : ";
    int c;
    cin >> c;
    if (c)
    {
        cout << "TO STORE THE RESULTANT MATRIX INT MAT A : ENTER 1 ELSE ENTER  0 : ";
        int c1;
        cin >> c1;
        if (c1 == 1)
        {
            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < m2; j++)
                {
                    matA[i][j] = mat[i][j];
                }
            }
        }
        else
        {
            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < m2; j++)
                {
                    matB[i][j] = mat[i][j];
                }
            }
        }
    }
    else
    {
        return;
    }
}

void sub_mat(int **matA, int **matB, int n1, int m1, int n2, int m2)
{
    system("cls");
    if (n1 != n2 || m1 != m2)
    {
        cout << "\nSUBTRACTION IS NOT POSSIBLE . ";
        return;
    }
    int **mat = new int *[n1];
    for (int i = 0; i < n1; i++)
    {
        mat[i] = new int[m2];
    }

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            mat[i][j] = matA[i][j] - matB[i][j];
        }
    }
    cout << "\nANSWER : \n";
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << "TO STORE THE RESULTANT MATRIX : ENTER 1 ELSE ENTER  0 : ";
    int c;
    cin >> c;
    if (c)
    {
        cout << "TO STORE THE RESULTANT MATRIX INT MAT A : ENTER 1 ELSE ENTER  0 : ";
        int c1;
        cin >> c1;
        if (c1 == 1)
        {
            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < m2; j++)
                {
                    matA[i][j] = mat[i][j];
                }
            }
        }
        else
        {
            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < m2; j++)
                {
                    matB[i][j] = mat[i][j];
                }
            }
        }
    }
    else
    {
        return;
    }
}
void transpose(int **matA, int n1, int m1)
{
    system("cls");

    cout << "\nTRANSPOSE : \n";
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            cout << matA[j][i] << " ";
        }
        cout << endl;
    }
}
void multiply(int **matA, int **matB, int n1, int m1, int n2, int m2)
{
    system("cls");
    if (n2 != m1)
    {
        cout << "\nMULTIPLICATION NOT POSSIBLE .";
        return;
    }
    int **mat = new int *[n1];
    for (int i = 0; i < n1; i++)
    {
        mat[i] = new int[m2];
    }

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            mat[i][j] = 0;
            for (int k = 0; k < m2; k++)
            {
                mat[i][j] += (matA[i][k] * matB[k][j]);
            }
        }
    }
    cout << "\nANSWER : \n";
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << "TO STORE THE RESULTANT MATRIX : ENTER 1 ELSE ENTER  0 : ";
    int c;
    cin >> c;
    if (c)
    {
        cout << "TO STORE THE RESULTANT MATRIX INT MAT A : ENTER 1 ELSE ENTER  0 : ";
        int c1;
        cin >> c1;
        if (c1 == 1)
        {
            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < m2; j++)
                {
                    matA[i][j] = mat[i][j];
                }
            }
        }
        else
        {
            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < m2; j++)
                {
                    matB[i][j] = mat[i][j];
                }
            }
        }
    }
    else
    {
        return;
    }
}
void show(int **mat, int n1, int m1)
{
    system("cls");
    cout << "\nMATRIX : \n";
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m1; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void matrices()
{
    system("cls");
    int n1, m1;
    int n2, m2;
    cout << "enter n*m (rows*column) for the matric A : ";
    cin >> n1 >> m1;
    int **matA = new int *[n1];
    for (int i = 0; i < n1; i++)
    {
        matA[i] = new int[m1];
    }
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m1; j++)
        {
            int value;
            cout << "enter the value of matA[" << i + 1 << "][" << j + 1 << "]  : ";
            cin >> value;
            matA[i][j] = value;
        }
    }

    cout << "enter n*m (rows*column) for the matric B : ";
    cin >> n2 >> m2;
    int **matB = new int *[n2];
    for (int i = 0; i < n2; i++)
    {
        matB[i] = new int[m2];
    }
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            int value;
            cout << "enter the value of matA[" << i + 1 << "][" << j + 1 << "]  : ";
            cin >> value;
            matB[i][j] = value;
        }
    }

    int a = 1;
    int m;
    system("cls");
    while (a)
    {

        cout << "ENTER O TO EXIT\nENTER 1 TO ADD TWO MATRICES\nENTER 2 TO SUBTRACT TWO MATRICES\nENTER 3 FOR TRANSPOSE OF MATRICES\nENTER 4 TO MULTIPLY TWO MATRICES\nENTER 5 TO DISPLAY MATRIX\nENTER YOUR CHOICE : ";
        cin >> a;
        switch (a)
        {
        case 0:
            break;
        case 1:
            cout << "\nENTER 1 TO SUBTRACT matA*matB ELSE ENTER 0";
            cin >> m;
            if (m)
                add_mat(matA, matB, n1, m1, n2, m2);
            else
                add_mat(matB, matA, n2, m2, n1, m1);

            break;
        case 2:
            cout << "\nENTER 1 TO SUBTRACT matA*matB ELSE ENTER 0";
            cin >> m;
            if (m)
                sub_mat(matA, matB, n1, m1, n2, m2);
            else
                sub_mat(matB, matA, n2, m2, n1, m1);
            break;
        case 3:
            cout << "for matA enter 1 and for matB enter 2 : ";

            cin >> m;
            if (m == 1)
            {
                transpose(matA, n1, m1);
            }
            else if (m == 2)
            {
                transpose(matB, n2, m2);
            }
            else
            {
                cout << "\nINVALID CHOICE.";
            }
            break;
        case 4:
            cout << "\nENTER 1 TO MULTIPLY matA*matB ELSE ENTER 0";
            cin >> m;
            if (m)
                multiply(matA, matB, n1, m1, n2, m2);
            else
                multiply(matB, matA, n2, m2, n1, m1);

            break;
        case 5:
            cout << "for matA enter 1 and for matB enter 2 : ";
            cin >> m;
            if (m == 1)
            {
                show(matA, n1, m1);
                ;
            }
            else if (m == 2)
            {
                show(matB, n2, m2);
            }
            else
            {
                cout << "\nINVALID CHOICE.";
            }
            break;
        }
    }
}

///

void one_degree()
{
    system("cls");
    double a,b;

    cout<<"\nSTANDARD 1 DEGREE EQUATION  IS AX+B=0  ";
    cout<<"\nENTER THE VALUE OF A AND B : ";
    cin>>a>>b;
    if(a==0)
    {
        cout<<"SYNTAX ERROR .";
        return ;
    }
    cout<<"\nTHE VALUE OF X IS : "<<-((double(b))/a);

}
void two_degree()
{
    system("cls");
    double a,b,c;
    cout<<"\nSTANDARD 2 DEGREE EQUATION  IS AX"<<char(253)<<"+BX+C=0 ";
    cout<<"\nENTER THE VALUE OF A ,B AND C : ";
    cin>>a>>b>>c;
    if(a==0 && b==0)
    {
        cout<<"SYNTAX ERROR .";
    }
    else if(a==0)
    {
        cout<<"\nTHE VALUE OF X IS : "<<-((double(c))/b);
    }
    else if((b*b)-(4*a*c)<0)
    {
        double d=-((b*b)-(4*a*c));
        cout<<"\nTHE VALUE OF X ARE : "<<-(b/(2*a))<<"+"<<(root(d)/(2*a))<<"i AND "<<-(b/(2*a))<<"-"<<(root(d)/(2*a))<<"i .";
    }
    else
    {
        cout<<"\nTHE VALUE OF X ARE : "<<double(-b - root((b*b)-(4*a*c)))/(2*a)<<" AND "<<double(-b + root((b*b)-(4*a*c)))/(2*a);
    }
}

void equation()
{
    int a = 1;
    while (a)
    {
        cout << "\nENTER DEGREE OF EQUATION : (1<=DEGREE<=2)\nENTER 0 TO EXIT :  ";
        cin >> a;
        switch (a)
        {
        case 1:
            one_degree();
            break;
        case 2:
            two_degree();
            break;
        case 0:
            return ;
        }
    }
}

///
void complex_number()
{
}


//
void graph()
{
    int n=21;
    int a, b;
    cout<<"Y = X ^A+B";
    cin>>a>>b;
    char mat[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==(n/2) && j==(n/2))
            {
                mat[i][j]='+';
            }
            else if(i==(n/2))
            {
                mat[i][j]='-';

            }
            else if(j==(n/2))
            {
                mat[i][j]='|';
            }
            else mat[i][j]=' ';

        }

    }

    for(int i=1;i<n/2;i++)
    {
        int x = n/2-i;
        int y = pow(-i,a) + b;
        //cout<<-i<<" "<<y<<endl;
        if(abs(y)<n/2)
        {
            if(y<0)
            {
                mat[x][y+n/2]='*';
            }
            else if(y>0)
            {
                cout<<x<<" "<<y<<endl;
                mat[x][y]='*';
            }
        }

    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<mat[i][j];

        }
        cout<<endl;
    }
}
int main()
{
    // cout << " \nsin S cos C cot c tan T sec s cosec t\n";
    // expression();
    //     // cout<<sin(3.14159265);
    //     // cout<<endl;
    // cout<< tan(p/2);
    // matrices();

  // equation();
  graph();

}