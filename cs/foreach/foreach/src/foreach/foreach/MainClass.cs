// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // �z��̏�����
        int[] array = new int[5];   // int�^�z��array��int�^�̗v�f��5�̔z��Ƃ��ď�����.

        // �z��ɒl���Z�b�g.
        array[0] = 7;   // array[0]��7���Z�b�g.
        array[1] = 4;   // array[1]��4���Z�b�g.
        array[2] = 6;   // array[2]��6���Z�b�g.
        array[3] = 10;  // array[3]��10���Z�b�g.
        array[4] = 3;   // array[4]��3���Z�b�g.

        // �z��̊e�v�f��foreach�ŌJ��Ԃ��o��.
        foreach (int val in array)    // array�̗v�f�����o����val�Ɋi�[����.�S�Ă̗v�f�����o���܂ŌJ��Ԃ�.
        {

            // ���o�����v�fval���o��.
            System.Console.WriteLine("val = " + val); // System.Console.WriteLine��val�̒l���o��.

        }

    }

}