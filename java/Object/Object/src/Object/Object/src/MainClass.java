//���C���N���X
class MainClass {	// MainClass�N���X�̒�`

	// Java�̃G���g���|�C���g
	public static void main(String[] args) {	// main���\�b�h�̒�`

		// String�I�u�W�F�N�g��Object�I�u�W�F�N�g�ɃL���X�g.
		String str = "ABC";	// str��"ABC"�ŏ�����.
		Object obj = str;	// str��Object�I�u�W�F�N�gobj�Ɋi�[.
		
		// �I�u�W�F�N�g�̒��g���o��.
		System.out.println("str = " + str);	// str���o��.
		System.out.println("obj = " + obj);	// obj���o��.
		
		// �Ǝ��̃I�u�W�F�N�gCustomObject��Object�I�u�W�F�N�g�ɃL���X�g.
		CustomObject custom = new CustomObject();	// custom�𐶐�.
		Object obj2 = custom;	// custom��Object�I�u�W�F�N�gobj2�Ɋi�[.
		
		// �I�u�W�F�N�g��toString���o��.
		System.out.println("custom.toString() = " + custom.toString());	// custom.toString()���o��.
		System.out.println("obj2.toString() = " + obj2.toString());	// obj2.toString()���o��.
		
	}
	
}