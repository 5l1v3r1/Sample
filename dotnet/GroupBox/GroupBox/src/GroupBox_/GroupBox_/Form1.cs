using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace GroupBox_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // �O���[�v�{�b�N�X���̃��W�I�{�^���̂���, �ǂꂪ�I������Ă��邩���`�F�b�N����.
            foreach (Control c in groupBox1.Controls)   // groupBox1.Controls��groupBox1��̂��ׂẴR���g���[�����w���̂�, ���̒�����foreach��Control�^��c�����o��.
            {
                RadioButton r = (RadioButton)c; // Control�^��c��RadioButton�^��r�ɃL���X�g.
                if (r.Checked)  // RadioButton��r���I������Ă�����.
                {
                    MessageBox.Show(r.Text);    // r.Text��\��.
                }
            }
        }
    }
}