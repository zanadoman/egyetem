<?php

namespace App\Http\Controllers;

use App\Models\Student;
use Illuminate\View\View;

class StudentController extends Controller
{
    public function add(): void
    {
        echo 'Add student';
    }

    public function get(): View
    {
        return view('student.list', ['records' => Student::getList()]);
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
