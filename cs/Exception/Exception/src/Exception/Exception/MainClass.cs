// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // ��O���N�������ȏꏊ.
        try // try�u���b�N
        {
            // x�̒l�̓���.
            System.Console.Write("x: ");    // x�̓��̓t�H�[��.
            int x = int.Parse(System.Console.ReadLine());   // ���͂��ꂽ�l��ϐ�x�ɑ��.

            // 0�ŏ��Z
            int y = 1 / x;  // x�ɂ���Ă�0�̏��Z�ɂȂ邩������Ȃ�.

            // y���o��.
            System.Console.WriteLine("y = " + y);   // y��System.Console.WriteLine�ŏo��.

        }
        catch (System.Exception e)  // System.Exception���E��.(catch�u���b�N)
        {

            // ��O�̓��e���o��.
            System.Console.WriteLine("e.ToString() = " + e.ToString()); // e.ToString()���\�b�h�̕Ԃ���������o��.

        }

    }

}