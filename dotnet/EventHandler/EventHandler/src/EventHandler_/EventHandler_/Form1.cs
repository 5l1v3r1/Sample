using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace EventHandler_
{
    public partial class Form1 : Form
    {

        // Form1�̃R���X�g���N�^.
        public Form1()
        {

            // �R���|�[�l���g�̏�����.
            InitializeComponent();

            // �C�x���g�n���h���̓o�^.
            button1.Click += new EventHandler(handler); // button1.Click�t�B�[���h��handler���Ă�EventHandler�ȃf���Q�[�g��o�^.

        }
        
        // �C�x���g�n���h��handler���菑���ŏ����Ă݂�.
        private void handler(object obj, EventArgs args)
        {

            // "Event!"��\��.
            MessageBox.Show("Event!");  // MessageBox.Show��"Event!"�ƕ\��.

        }

    }
}