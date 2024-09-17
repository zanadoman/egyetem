<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class StudentController extends Controller
{
    public function add(): void
    {
        echo 'Add student';
    }

    public function get(): void
    {
        echo 'Get student';
    }

    public function update(): void
    {
        echo 'Update student';
    }

    public function delete(): void
    {
        echo 'Delete student';
    }
}
