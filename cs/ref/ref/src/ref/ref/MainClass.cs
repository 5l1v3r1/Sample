// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // �ϐ��̏�����
        int a = 10; // a��10�ɏ�����.
        int b = 20; // b��20�ɏ�����.

        // a��b�̒l���o��.
        System.Console.WriteLine("a = " + a + ", b = " + b);    // System.Console.WriteLine��a��b�̒l���o��.

        // a��b������.
        Swap(ref a, ref b); // a��b�̒l��Swap���\�b�h�Ō���.(�Q�Ɠn������ɂ�ref���w�肷��. ref�Ŏw�肷��ϐ��͗\�ߏ���������Ă��Ȃ���΂Ȃ�Ȃ�.)

        // a��b�̒l���o��.
        System.Console.WriteLine("a = " + a + ", b = " + b);    // System.Console.WriteLine��a��b�̒l���o��.

    }

    // �X���b�v���\�b�h
    public static void Swap(ref int a, ref int b)  // Swap���\�b�h(static���\�b�h)�̒�`
    {

        // �ϐ��̐錾
        int tmp;    // �ꎞ�I�ɒl���i�[���Ă���int�^�ϐ�tmp.

        // a��b�̒l����������.
        tmp = a;    // tmp��a����.
        a = b;      // a��b����.
        b = tmp;    // b��tmp����.

    }

}