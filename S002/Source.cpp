#include <iostream>

int main()
{
	char s[256];
	char t[256];
	char m1[] = "String1\n";
	char m2[] = "String2\n";
	char f[] = "%s";
	char fgs[] = "1\n";
	char fls[] = "-1\n";
	char fes[] = "0\n";
	_asm 
	{
		//�������� 1 ������
		lea ebx, m1
		push ebx
		lea ecx, f
		push ecx
		call printf
		add esp, 8

		//������ 1 ������
		lea ebx, s
		push ebx
		lea ecx, f
		push ecx
		call scanf
		add esp, 8

		//�������� 2 ������
		lea ebx, m2
		push ebx
		lea ecx, f
		push ecx
		call printf
		add esp, 8

		//������ 2 ������
		lea ebx, t
		push ebx
		lea ecx, f
		push ecx
		call scanf
		add esp, 8

		//���������� ����� �������� 1 ������
		lea ebx, s
		dec ebx
		lea ecx, t
		dec ecx
		b1:
			inc ebx
			inc ecx
			mov al,[ebx]
			mov dl,[ecx]
			cmp al, 0
			
			je b2//������� ����� 1 ������

			cmp dl,0
			je f3//������� ����� 2 ������ (2 ������)
			cmp al,dl
			je b1//c������ � ������� ����� (���������� ����)
			
			jb f4//������ � 1 ������ ������ ������� �� 2
			jmp f3//������ �� 2 ������ ������ ������� � 1 

		b2://����� � ������ ������
			cmp dl,0
			je f5//����� 2 ������ (������ �����)
			jmp f4// 2 ������ ������

	f3: //1 ������
		lea ebx,fgs
			push ebx
			lea ecx,f
			push ecx
			call printf
			add esp,8
			jmp end
	f4://2 ������
		lea ebx,fls
			push ebx
			lea ecx,f
			push ecx
			call printf
			add esp,8
			jmp end
	f5://������ �����
		lea ebx,fes
			push ebx
			lea ecx,f
			push ecx
			call printf
			add esp,8

	end:

	}
	system("pause");
}
