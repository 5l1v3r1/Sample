// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // int�^�ϐ���ToString().
        int i = 10; // int�^��i��10����.
        string str1 = i.ToString(); // str1��i.ToString()�̖߂�l���i�[.
        Console.WriteLine("str1 = " + str1);  // str1�̓��e���o��.
        str1 = ((Object)i).ToString();  // Object�ɃL���X�g����ToString()��str1�Ɋi�[.
        Console.WriteLine("str1 = " + str1);  // str1�̓��e���o��.

        // �z���ToString().
        int[] array = new int[3];   // int�^�z��array(�v�f��3.)
        array[0] = 0;   // 0�Ԗڂ�0.
        array[1] = 1;   // 1�Ԗڂ�1.
        array[2] = 2;   // 2�Ԗڂ�2.
        string str2 = array.ToString(); // str2��array.ToString()�̖߂�l���i�[.
        Console.WriteLine("str2 = " + str2);  // str2�̓��e���o��.
        str2 = ((Object)array).ToString();  // Object�ɃL���X�g����ToString()��str2�Ɋi�[.
        Console.WriteLine("str2 = " + str2);  // str2�̓��e���o��2

        // BaseClass�I�u�W�F�N�g��ToString().
        BaseClass obj = new BaseClass();    // new��BaseClass�I�u�W�F�N�g�𐶐���, obj�Ɋi�[.
        string str3 = obj.ToString();    // str3��obj.ToString()�̖߂�l���i�[.
        Console.WriteLine("str3 = " + str3);  // str3�̓��e���o��.
        str3 = ((Object)obj).ToString();    // Object�ɃL���X�g����ToString()��str3�Ɋi�[.
        Console.WriteLine("str3 = " + str3);  // str3�̓��e���o��.

    }

}