// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // Class1�I�u�W�F�N�g�̐���.
        Class1 c1 = new Class1();   // Class1�I�u�W�F�N�gc1�̐���.
        c1.I = -5;  // -5���Z�b�g.
        System.Console.WriteLine("c1.I = " + c1.I); // c1.I���o��.
        c1.I = 10;  // 10���Z�b�g.
        System.Console.WriteLine("c1.I = " + c1.I); // c1.I���o��.
        c1.Str = "";    // ""���Z�b�g.
        System.Console.WriteLine("c1.Str = " + c1.Str); // c1.Str���o��.
        c1.Str = "ABC"; // "ABC"���Z�b�g.
        System.Console.WriteLine("c1.Str = " + c1.Str); // c1.Str���o��.

    }

}