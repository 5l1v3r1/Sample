using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace OpenFileDialog_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        // ���j���[�A�C�e��"�J��"���N���b�N���ꂽ���̏���.
        private void menuItem3_Click(object sender, EventArgs e)
        {

            // �t�@�C�����͋�ɏ�����.
            openFileDialog1.FileName = "";  // openFileDialog1.FileName��""�����Ă���.

            // "�J��"�t�@�C���_�C�A���O�̕\��.
            if (openFileDialog1.ShowDialog() == DialogResult.OK)    // openFileDialog1.ShowDialog()�̖߂�l��DialogResult.OK�Ȃ�.
            {

                // �I�����ꂽ�t�@�C������\��.
                MessageBox.Show(openFileDialog1.FileName);  // MessageBox.Show��openFileDialog1.FileName��\��.

            }

        }
    }
}