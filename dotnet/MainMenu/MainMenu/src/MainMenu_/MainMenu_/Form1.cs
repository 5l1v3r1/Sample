using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace MainMenu_
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

            // "Open!"��\��.
            MessageBox.Show("Open!");  // MessageBox.Show��"Open!"�ƕ\��.

        }
    }
}