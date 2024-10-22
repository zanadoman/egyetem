<?php

namespace App\Http\Controllers;

use App\Models\Message;
use Illuminate\Http\Request;

class MessageController extends Controller
{
    public function index()
    {
        $messages = Message::all();
        return view('messages', compact('messages'));
    }

    public function store(Request $request)
    {
        Message::create($this->validate($request));
        return redirect()->back()->with('success', 'message sent');
    }

    public function update(Request $request, $id)
    {
        Message::find($id)->update($this->validate($request));
        return redirect()->back()->with('success', 'message updated');
    }

    public function destroy($id)
    {
        Message::find($id)->delete();
        return redirect()->back()->with('success', 'message deleted');
    }

    private function validate(Request $request)
    {
        return $request->validate([
            'title' => 'string|required',
            'content' => 'string|required'
        ]);
    }
}
