using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Movement : MonoBehaviour
{
    public CharacterController controller;
    public float speed = 10f;
    public float Gravity = -9.81f; 
    Vector3 GForce;
    bool IsGrounded;
    public float SphereRadius = 0.4f;
    public Transform GroundCheck;
    public LayerMask GroundMask; 
    public float JumpHeight = 4f;
    public float CrouchedHeight = 1f;
    public float CrouchedSpeed = 5f;
    public float NormalSpeed = 10f;
    public float SprintSpeed = 20f;
    // Update is called once per frame
    void Update()
    {
        IsGrounded = Physics.CheckSphere(GroundCheck.position,SphereRadius,GroundMask);

        if (IsGrounded && GForce.y < 0)
        {
            GForce.y= -2f;   
        }

        if (Input.GetKeyDown(KeyCode.Space) && IsGrounded)
        {
            GForce.y = Mathf.Sqrt(JumpHeight * -2f * Gravity);
        }

        if (Input.GetKeyDown(KeyCode.LeftControl))
        {
            transform.localScale = new Vector3(1,CrouchedHeight,1);
            speed = CrouchedSpeed;
        }

        if (Input.GetKeyUp(KeyCode.LeftControl))
        {
            transform.localScale = new Vector3(1,2,1);
            speed = NormalSpeed;
        }

        if (Input.GetKeyDown(KeyCode.LeftShift))
        {
            speed = SprintSpeed;
        }

        if (Input.GetKeyUp(KeyCode.LeftShift))
        {
            speed = NormalSpeed;
        }

        float x = Input.GetAxis("Horizontal");
        float z = Input.GetAxis("Vertical");

        Vector3 move = transform.right * x + transform.forward * z;

        controller.Move(move * speed  * Time.deltaTime);

        GForce.y += Gravity * Time.deltaTime;

        controller.Move(GForce * Time.deltaTime);
    }
}
